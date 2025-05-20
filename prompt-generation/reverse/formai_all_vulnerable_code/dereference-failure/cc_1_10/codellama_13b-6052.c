//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: visionary
/*
 * Binary search tree example program
 *
 * This program creates a binary search tree and performs various operations
 * on it, such as inserting, searching, and deleting nodes.
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Search for a node with the given key
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (root->key > key) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

// Insert a node with the given key
void insertNode(struct Node** root, int key) {
    struct Node* node = newNode(key);
    if (*root == NULL) *root = node;
    else {
        struct Node* curr = *root;
        while (1) {
            if (curr->key > key) {
                if (curr->left == NULL) {
                    curr->left = node;
                    break;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == NULL) {
                    curr->right = node;
                    break;
                }
                curr = curr->right;
            }
        }
    }
}

// Delete a node with the given key
void deleteNode(struct Node** root, int key) {
    if (*root == NULL) return;
    if ((*root)->key == key) {
        struct Node* temp = *root;
        *root = (*root)->left;
        free(temp);
        return;
    }
    deleteNode(&(*root)->left, key);
    deleteNode(&(*root)->right, key);
}

// Print the keys in the tree in order
void printTree(struct Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->key);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);
    insertNode(&root, 1);

    // Search for a node
    struct Node* node = searchNode(root, 4);
    if (node != NULL) printf("Found %d\n", node->key);

    // Delete a node
    deleteNode(&root, 4);

    // Print the tree
    printTree(root);

    return 0;
}