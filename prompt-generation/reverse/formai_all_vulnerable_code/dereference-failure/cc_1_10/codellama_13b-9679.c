//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: expert-level
/*
 * Binary Search Tree
 *
 * A program to demonstrate the implementation of a binary search tree in C
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node* newNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
void insertNode(node** root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    // Otherwise, find the correct position for the node
    node* current = *root;
    while (current != NULL) {
        if (data < current->data) {
            // Insert the node to the left
            if (current->left == NULL) {
                current->left = newNode(data);
                break;
            } else {
                current = current->left;
            }
        } else {
            // Insert the node to the right
            if (current->right == NULL) {
                current->right = newNode(data);
                break;
            } else {
                current = current->right;
            }
        }
    }
}

// Function to traverse the binary search tree
void traverse(node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverse(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    traverse(root->right);
}

// Function to search for a node in the binary search tree
node* search(node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    // If the data is found, return the node
    if (root->data == data) {
        return root;
    }

    // Otherwise, search the left and right subtrees
    node* left = search(root->left, data);
    if (left != NULL) {
        return left;
    }

    node* right = search(root->right, data);
    if (right != NULL) {
        return right;
    }

    // If the node is not found, return NULL
    return NULL;
}

int main() {
    // Create a new binary search tree
    node* root = NULL;

    // Insert some nodes into the tree
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);
    insertNode(&root, 1);

    // Traverse the tree
    traverse(root);
    printf("\n");

    // Search for a node in the tree
    node* found = search(root, 7);
    if (found != NULL) {
        printf("Found node with data %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}