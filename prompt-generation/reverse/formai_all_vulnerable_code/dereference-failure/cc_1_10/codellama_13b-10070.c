//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: complex
/*
 * A unique C Binary search trees example program in a complex style
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to insert a new node into the binary search tree
void insert(struct node **root, int data) {
    // If the root is NULL, create a new node and assign it to the root
    if (*root == NULL) {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    // If the data is less than the root's data, recursively search the left subtree
    else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    }
    // If the data is greater than the root's data, recursively search the right subtree
    else {
        insert(&((*root)->right), data);
    }
}

// Function to search for a node in the binary search tree
struct node *search(struct node *root, int data) {
    // If the root is NULL, the node is not found
    if (root == NULL) {
        return NULL;
    }
    // If the data is found, return the node
    else if (root->data == data) {
        return root;
    }
    // If the data is less than the root's data, recursively search the left subtree
    else if (data < root->data) {
        return search(root->left, data);
    }
    // If the data is greater than the root's data, recursively search the right subtree
    else {
        return search(root->right, data);
    }
}

// Function to delete a node from the binary search tree
void delete(struct node **root, int data) {
    // If the root is NULL, the node is not found
    if (*root == NULL) {
        return;
    }
    // If the data is found, delete the node and balance the tree
    else if ((*root)->data == data) {
        struct node *temp = *root;
        if ((*root)->left == NULL && (*root)->right == NULL) {
            *root = NULL;
        }
        else if ((*root)->left == NULL) {
            *root = (*root)->right;
        }
        else if ((*root)->right == NULL) {
            *root = (*root)->left;
        }
        else {
            struct node *successor = (*root)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            (*root)->data = successor->data;
            delete(&((*root)->right), successor->data);
        }
        free(temp);
    }
    // If the data is less than the root's data, recursively search the left subtree
    else if (data < (*root)->data) {
        delete(&((*root)->left), data);
    }
    // If the data is greater than the root's data, recursively search the right subtree
    else {
        delete(&((*root)->right), data);
    }
}

// Function to print the binary search tree
void print(struct node *root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;

    // Insert nodes into the binary search tree
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 10);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 7);
    insert(&root, 11);
    insert(&root, 12);

    // Search for a node in the binary search tree
    struct node *node = search(root, 4);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    }
    else {
        printf("Node with data 4 not found\n");
    }

    // Delete a node from the binary search tree
    delete(&root, 4);

    // Print the binary search tree
    printf("Binary search tree after deletion:\n");
    print(root);

    // Free the memory used by the binary search tree
    free(root);

    return 0;
}