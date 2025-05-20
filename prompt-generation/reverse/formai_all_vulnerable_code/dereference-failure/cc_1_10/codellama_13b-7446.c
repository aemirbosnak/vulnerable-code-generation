//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: complex
/*
 * Binary Search Trees Example Program
 *
 * This program demonstrates how to implement a binary search tree in C.
 * It allows the user to insert, search, and delete nodes in the tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary search tree node
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the tree
void insertNode(Node* root, int value) {
    if (root == NULL) {
        root = newNode(value);
    } else if (value < root->value) {
        insertNode(root->left, value);
    } else if (value > root->value) {
        insertNode(root->right, value);
    }
}

// Function to search for a node in the tree
Node* searchNode(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value == root->value) {
        return root;
    } else if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to delete a node from the tree
void deleteNode(Node* root, int value) {
    if (root == NULL) {
        return;
    } else if (value == root->value) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left != NULL) {
            Node* temp = root->left;
            free(root);
            root = temp;
        } else if (root->right != NULL) {
            Node* temp = root->right;
            free(root);
            root = temp;
        }
    } else if (value < root->value) {
        deleteNode(root->left, value);
    } else {
        deleteNode(root->right, value);
    }
}

// Function to print the tree
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->value);
    printTree(root->right);
}

int main() {
    // Create a new binary search tree
    Node* root = NULL;

    // Insert some nodes into the tree
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 8);
    insertNode(root, 11);

    // Search for a node in the tree
    Node* node = searchNode(root, 8);
    if (node != NULL) {
        printf("Found node with value %d\n", node->value);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the tree
    deleteNode(root, 3);
    printf("Deleted node with value %d\n", 3);

    // Print the tree
    printTree(root);

    return 0;
}