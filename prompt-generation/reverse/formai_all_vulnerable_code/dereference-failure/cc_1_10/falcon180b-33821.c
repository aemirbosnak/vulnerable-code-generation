//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of each node in the tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node with the given data in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the tree inorder traversal
void printInorder(Node* root) {
    if (root!= NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Main function to test the tree operations
int main() {
    Node* root = NULL;
    // Insert nodes with data 10, 20, 30, 40, 50
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    // Search for node with data 20
    Node* searchResult = search(root, 20);
    if (searchResult!= NULL) {
        printf("Node found with data %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }
    // Print the tree inorder traversal
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");
    return 0;
}