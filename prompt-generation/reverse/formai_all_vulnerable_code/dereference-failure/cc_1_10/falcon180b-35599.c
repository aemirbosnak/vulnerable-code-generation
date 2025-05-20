//Falcon-180B DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* newNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a node into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Recursive function to print the tree in order traversal
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Recursive function to print the tree in pre-order traversal
void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Recursive function to print the tree in post-order traversal
void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert nodes into the tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    // Print the tree in order traversal
    printf("Tree in order traversal:\n");
    printInOrder(root);

    // Print the tree in pre-order traversal
    printf("\nTree in pre-order traversal:\n");
    printPreOrder(root);

    // Print the tree in post-order traversal
    printf("\nTree in post-order traversal:\n");
    printPostOrder(root);

    return 0;
}