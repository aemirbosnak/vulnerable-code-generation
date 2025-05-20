//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: scalable
// Binary Search Tree Example Program
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insertNode(struct Node** root, int data) {
    // If the root is NULL, create a new node
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    // If the data is less than the root's data, insert it in the left subtree
    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
        return;
    }

    // If the data is greater than the root's data, insert it in the right subtree
    if (data > (*root)->data) {
        insertNode(&(*root)->right, data);
        return;
    }
}

// Function to search for a node in the tree
struct Node* searchNode(struct Node* root, int data) {
    // If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is found, return the node
    if (root->data == data) {
        return root;
    }

    // If the data is less than the root's data, search in the left subtree
    if (data < root->data) {
        return searchNode(root->left, data);
    }

    // If the data is greater than the root's data, search in the right subtree
    if (data > root->data) {
        return searchNode(root->right, data);
    }

    // If the data is not found, return NULL
    return NULL;
}

// Function to delete a node from the tree
void deleteNode(struct Node** root, int data) {
    // If the root is NULL, return
    if (*root == NULL) {
        return;
    }

    // If the data is found, delete the node
    if ((*root)->data == data) {
        struct Node* temp = *root;
        *root = NULL;
        free(temp);
        return;
    }

    // If the data is less than the root's data, delete it in the left subtree
    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
        return;
    }

    // If the data is greater than the root's data, delete it in the right subtree
    if (data > (*root)->data) {
        deleteNode(&(*root)->right, data);
        return;
    }
}

// Main function
int main() {
    // Create a new node
    struct Node* root = newNode(10);

    // Insert nodes into the tree
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 12);

    // Search for a node
    struct Node* node = searchNode(root, 15);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    deleteNode(&root, 15);

    // Search for a node again
    node = searchNode(root, 15);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Free the memory
    free(root);

    return 0;
}