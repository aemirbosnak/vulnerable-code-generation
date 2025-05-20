//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the node of the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with a given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to search for a node in the binary search tree
Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to print the binary search tree in in-order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test the binary search tree implementation
int main() {
    Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    printf("In-order traversal of the binary search tree: ");
    printTree(root);
    return 0;
}