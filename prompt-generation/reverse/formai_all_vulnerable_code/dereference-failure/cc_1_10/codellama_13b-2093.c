//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: genius
/*
 * Binary Search Tree Example Program
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(data);
    }

    // If the data is less than the root node, insert it in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // If the data is greater than the root node, insert it in the right subtree
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to traverse the tree in inorder fashion
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to find the minimum element in the tree
struct Node* minValue(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Function to find the maximum element in the tree
struct Node* maxValue(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

// Function to delete a node in the tree
struct Node* deleteNode(struct Node* root, int data) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is less than the root node, delete it in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }

    // If the data is greater than the root node, delete it in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }

    // If the data is found in the root node, delete it and return the left subtree
    else {
        // If the root node has no left child, return the right subtree
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // If the root node has no right child, return the left subtree
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // If the root node has both left and right children, find the minimum element in the right subtree and replace the root node with it
        struct Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);

    printf("Inorder traversal of the constructed tree is: \n");
    inorder(root);

    printf("\nMinimum value in the tree is %d\n", minValue(root)->data);
    printf("Maximum value in the tree is %d\n", maxValue(root)->data);

    root = deleteNode(root, 2);

    printf("Inorder traversal of the modified tree is: \n");
    inorder(root);

    return 0;
}