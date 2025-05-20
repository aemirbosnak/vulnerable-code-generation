//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into the binary search tree
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

// Function to search for a node with the given data in the binary search tree
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

// Function to print the binary search tree in order traversal
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
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    printf("Binary search tree in order traversal:\n");
    printTree(root);

    printf("\nSearching for 20...\n");
    Node* foundNode = searchNode(root, 20);
    if (foundNode!= NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    printf("\nSearching for 25...\n");
    foundNode = searchNode(root, 25);
    if (foundNode!= NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}