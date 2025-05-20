//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the BST
struct Node* insert(struct Node* root, int data) {
    // If the root is null, create a new node and return it
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // If the data is less than the root's data, move to the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the data is greater than the root's data, move to the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to search for a node with the given data in the BST
struct Node* search(struct Node* root, int data) {
    // If the root is null or the data is found, return the node
    if (root == NULL || root->data == data) {
        return root;
    }

    // If the data is less than the root's data, move to the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }
    // If the data is greater than the root's data, move to the right subtree
    else if (data > root->data) {
        return search(root->right, data);
    }

    // If the data is not found in the tree, return null
    return NULL;
}

// Function to traverse and print the elements of the BST in inorder
void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes with the following data into the tree: 5 3 7 1 9
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);

    // Traverse and print the elements of the tree in inorder
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}