//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: excited
// Unique C Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to insert a node into the tree
void insertNode(struct Node **root, int data) {
    // If the tree is empty, create a new node and insert the data
    if (*root == NULL) {
        *root = (struct Node *)malloc(sizeof(struct Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        // If the data is less than the current node, recurse left
        if (data < (*root)->data) {
            insertNode(&((*root)->left), data);
        } else {
            // If the data is greater than the current node, recurse right
            insertNode(&((*root)->right), data);
        }
    }
}

// Function to search for a node in the tree
int searchNode(struct Node *root, int data) {
    // If the root is NULL, the data is not in the tree
    if (root == NULL) {
        return 0;
    }

    // If the data is found, return 1
    if (root->data == data) {
        return 1;
    }

    // If the data is less than the current node, recurse left
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        // If the data is greater than the current node, recurse right
        return searchNode(root->right, data);
    }
}

// Function to delete a node from the tree
void deleteNode(struct Node **root, int data) {
    // If the tree is empty, return
    if (*root == NULL) {
        return;
    }

    // If the data is found, delete the node and update the pointers
    if ((*root)->data == data) {
        struct Node *temp = *root;
        *root = (*root)->left ? (*root)->left : (*root)->right;
        free(temp);
    } else {
        // If the data is less than the current node, recurse left
        if (data < (*root)->data) {
            deleteNode(&((*root)->left), data);
        } else {
            // If the data is greater than the current node, recurse right
            deleteNode(&((*root)->right), data);
        }
    }
}

// Function to print the tree
void printTree(struct Node *root) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    printf("%d ", root->data);

    // Recurse left and right
    printTree(root->left);
    printTree(root->right);
}

// Main function
int main() {
    // Create a tree
    struct Node *root = NULL;

    // Insert some nodes
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);
    insertNode(&root, 1);

    // Print the tree
    printTree(root);

    // Search for a node
    printf("\nSearching for 4... ");
    if (searchNode(root, 4)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    // Delete a node
    printf("Deleting node with value 2...\n");
    deleteNode(&root, 2);

    // Print the tree again
    printf("Tree after deletion:\n");
    printTree(root);

    // Search for a node again
    printf("Searching for 4... ");
    if (searchNode(root, 4)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    return 0;
}