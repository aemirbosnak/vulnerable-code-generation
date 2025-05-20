//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into binary search tree
void insert(struct node** root, int data) {
    // If the tree is empty, create a new node as root
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    // Otherwise, insert data into the tree
    struct node* node = *root;
    while (true) {
        if (data < node->data) {
            if (node->left == NULL) {
                node->left = newNode(data);
                return;
            }
            node = node->left;
        } else {
            if (node->right == NULL) {
                node->right = newNode(data);
                return;
            }
            node = node->right;
        }
    }
}

// Function to print binary search tree in pre-order traversal
void preOrder(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Function to search for data in binary search tree
bool search(struct node* root, int data) {
    // If the tree is empty, data is not found
    if (root == NULL)
        return false;

    // If data is found, return true
    if (root->data == data)
        return true;

    // Otherwise, continue searching in left or right subtree
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main() {
    // Create binary search tree
    struct node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Print binary search tree
    printf("Binary search tree: ");
    preOrder(root);
    printf("\n");

    // Search for data in binary search tree
    int data = 60;
    if (search(root, data))
        printf("%d found in binary search tree.\n", data);
    else
        printf("%d not found in binary search tree.\n", data);

    return 0;
}