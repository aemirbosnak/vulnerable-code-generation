//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a node in the tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to print the tree in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test the tree operations
int main() {
    Node* root = NULL;

    // Insert some nodes into the tree
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    // Print the tree in order traversal
    printf("Tree in order traversal:\n");
    printTree(root);

    // Search for a node in the tree
    Node* foundNode = searchNode(root, 30);
    if (foundNode!= NULL) {
        printf("\nNode with data 30 found!\n");
    } else {
        printf("\nNode with data 30 not found.\n");
    }

    return 0;
}