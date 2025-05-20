//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: portable
// Portable C Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *node = malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insertNode(struct Node *root, int key) {
    if (root == NULL) {
        root = createNode(key);
        return;
    }
    if (key < root->key) {
        insertNode(root->left, key);
    } else {
        insertNode(root->right, key);
    }
}

// Function to search for a node in the tree
struct Node *searchNode(struct Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == root->key) {
        return root;
    }
    if (key < root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

// Function to delete a node from the tree
void deleteNode(struct Node *root, int key) {
    if (root == NULL) {
        return;
    }
    if (key == root->key) {
        free(root);
        return;
    }
    if (key < root->key) {
        deleteNode(root->left, key);
    } else {
        deleteNode(root->right, key);
    }
}

// Function to traverse the tree
void traverseTree(struct Node *root) {
    if (root == NULL) {
        return;
    }
    traverseTree(root->left);
    printf("%d ", root->key);
    traverseTree(root->right);
}

int main() {
    struct Node *root = NULL;

    // Insert nodes into the tree
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);

    // Search for a node in the tree
    struct Node *node = searchNode(root, 20);
    if (node != NULL) {
        printf("Node found: %d\n", node->key);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the tree
    deleteNode(root, 20);

    // Traverse the tree
    traverseTree(root);

    return 0;
}