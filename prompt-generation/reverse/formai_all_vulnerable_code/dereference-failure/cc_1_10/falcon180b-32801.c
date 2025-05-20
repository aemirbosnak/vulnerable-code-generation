//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert data into the tree
struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Search for a node with the given data
struct Node* search(struct Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print the tree in pre-order traversal
void printPreOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Main function
int main() {
    struct Node *root = NULL;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the tree
    printf("Pre-order traversal of the tree is: ");
    printPreOrder(root);

    return 0;
}