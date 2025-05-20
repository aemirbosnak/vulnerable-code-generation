//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Struct for each node in the binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
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

// Function to insert a value into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
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

// Main function
int main() {
    // Create the initial empty tree
    Node* tree = NULL;

    // Insert values into the tree
    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 7);
    tree = insert(tree, 2);
    tree = insert(tree, 4);
    tree = insert(tree, 6);
    tree = insert(tree, 8);

    // Print the tree in order traversal
    printf("Tree in order traversal:\n");
    printTree(tree);

    return 0;
}