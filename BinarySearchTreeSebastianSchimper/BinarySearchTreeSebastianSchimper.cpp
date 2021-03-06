// BinarySearchTreeSebastianSchimper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h" // somehow needed for the precompiler in visual studio
#include <assert.h>
#include <iostream>
#include <ctime>

struct node {
	int data;
	node* left_branch;
	node* right_branch;
};

struct node* newNode(int integer) {
	struct node* temp = new node;
	temp->data = integer;
	temp->left_branch = NULL;
	temp->right_branch = NULL;
	return temp;
}


struct node* insert(node* node, int data) {
	
	if (node == NULL) {
		std::cout << "Node with data " << data << " inserted..." << std::endl;
		return newNode(data);
	}
	if (data < node->data) {
		node->left_branch = insert(node->left_branch, data);
	}
	else if (data >= node->data) {
		node->right_branch = insert(node->right_branch, data);
	}

	return node;
}

struct node* findNode(node* root, int data) {

	if (root == NULL || root->data == data) {
		std::cout << "Node found! Yay!" << std::endl;
		return root;
	}
	if (root->data < data) {
		if (root->right_branch == NULL) {
			std::cout << "Node was not on the tree..." << std::endl;
		}
		else {
			return findNode(root->right_branch, data);
		}
	}
	else if (root->data >= data) {
		if (root->left_branch == NULL) {
			std::cout << "Node was not on the tree..." << std::endl;
		}
		else {
			return findNode(root->left_branch, data);
		}
	}
}

struct node* createTree(int numbers[]) {

	std::cout << "Building tree..." << std::endl;
	struct node* root = NULL;
	root = insert(root, numbers[0]);

	for (int i = 1; i < 10; i++) {
		insert(root, numbers[i]);
	}

	return root; // return the root node with all its branches
}

void deallocate(node* node) {

	if (node == NULL) {
		return;
	}

	deallocate(node->left_branch);
	deallocate(node->right_branch);

	delete node;
}

int main()
{
	// create random numbers ...
	std::cout << "Generating 10 random numbers..." << std::endl;

	srand(time(NULL));
	int r0 = rand() % 100;
	int r1 = rand() % 100;
	int r2 = rand() % 100;
	int r3 = rand() % 100;
	int r4 = rand() % 100;
	int r5 = rand() % 100;
	int r6 = rand() % 100;
	int r7 = rand() % 100;
	int r8 = rand() % 100;
	int r9 = rand() % 100;
	
	// ..., store them in an array ...
	int numberArray[] = {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9};

	// ... and create the tree
	struct node* myTree = createTree(numberArray);

	// Choose random number from array and find it on the tree ...
	std::cout << "Pick random number out of generated random numbers..." << std::endl;
	int findRandomNumber = rand() % 10;
	int randomNumberFromArray = numberArray[findRandomNumber];
	std::cout << "Pick random number out of generated random numbers... " << "-> "<< randomNumberFromArray << std::endl;

	// ... and find it
	std::cout << "Looking for node with number " << randomNumberFromArray << "..." << std::endl;
	struct node* myFoundTreeNode = findNode(myTree, randomNumberFromArray);

	// delete nodes to free memory
	std::cout << "Deleting tree nodes to de-allocate memory..." << std::endl;
	deallocate(myTree);

	std::cout << "All done!" << std::endl;
	return 0;
}

