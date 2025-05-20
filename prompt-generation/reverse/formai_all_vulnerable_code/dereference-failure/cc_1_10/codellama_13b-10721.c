//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: detailed
// Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct node* insert(struct node* root, int data) {
    // If the root is NULL, create a new node and return it
    if (root == NULL) {
        return newNode(data);
    }

    // If the data is less than the root's data, insert it in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // If the data is greater than the root's data, insert it in the right subtree
    else {
        root->right = insert(root->right, data);
    }

    // Return the updated root
    return root;
}

// Function to search for a node with a given data value
struct node* search(struct node* root, int data) {
    // If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is found in the root's data, return the root
    if (root->data == data) {
        return root;
    }

    // If the data is less than the root's data, search in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }

    // If the data is greater than the root's data, search in the right subtree
    else {
        return search(root->right, data);
    }
}

// Function to delete a node with a given data value
struct node* delete(struct node* root, int data) {
    // If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is found in the root's data, delete the root
    if (root->data == data) {
        struct node* temp = root;
        root = NULL;
        free(temp);
        return root;
    }

    // If the data is less than the root's data, delete in the left subtree
    if (data < root->data) {
        root->left = delete(root->left, data);
    }

    // If the data is greater than the root's data, delete in the right subtree
    else {
        root->right = delete(root->right, data);
    }

    // Return the updated root
    return root;
}

// Function to print the binary search tree
void print(struct node* root) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    // Print the data in the root
    printf("%d ", root->data);

    // Print the left subtree
    print(root->left);

    // Print the right subtree
    print(root->right);
}

int main() {
    // Create a new binary search tree
    struct node* root = NULL;

    // Insert some data into the binary search tree
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 8);

    // Search for a node with the data value of 3
    struct node* node = search(root, 3);
    if (node != NULL) {
        printf("Found node with data value of 3\n");
    }
    else {
        printf("Node with data value of 3 not found\n");
    }

    // Delete a node with the data value of 5
    root = delete(root, 5);

    // Print the binary search tree
    printf("Binary search tree after deletion:\n");
    print(root);

    return 0;
}