//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: optimized
// Binary search tree implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
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

// Function to insert a node into the binary search tree
void insert(struct Node** root, int data) {
    // If the root is NULL, create a new node and insert the data
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    // If the data is less than the root, insert it in the left subtree
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }
    // If the data is greater than the root, insert it in the right subtree
    else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
bool search(struct Node* root, int data) {
    // If the root is NULL, the data is not present in the tree
    if (root == NULL) {
        return false;
    }

    // If the data is less than the root, search in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }
    // If the data is greater than the root, search in the right subtree
    else if (data > root->data) {
        return search(root->right, data);
    }
    // If the data is equal to the root, return true
    else {
        return true;
    }
}

// Function to delete a node from the binary search tree
void delete(struct Node** root, int data) {
    // If the root is NULL, the data is not present in the tree
    if (*root == NULL) {
        return;
    }

    // If the data is less than the root, delete it from the left subtree
    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    }
    // If the data is greater than the root, delete it from the right subtree
    else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    }
    // If the data is equal to the root, delete the node and adjust the links
    else {
        // If the node has no children, delete the node
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        // If the node has one child, delete the node and link the child to the parent
        else if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        // If the node has two children, find the minimum value in the right subtree and replace the node with it
        else {
            struct Node* temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            delete(&(*root)->right, temp->data);
        }
    }
}

// Function to traverse the binary search tree
void traverse(struct Node* root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%d ", root->data);
    traverse(root->right);
}

int main() {
    // Create a new node and insert it into the binary search tree
    struct Node* root = newNode(10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 25);

    // Search for a node in the binary search tree
    if (search(root, 15)) {
        printf("Found 15 in the binary search tree.\n");
    }
    else {
        printf("Did not find 15 in the binary search tree.\n");
    }

    // Delete a node from the binary search tree
    delete(&root, 5);

    // Traverse the binary search tree
    printf("Inorder traversal of the binary search tree: ");
    traverse(root);
    printf("\n");

    return 0;
}