//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: single-threaded
/*
 * Binary search tree example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary search tree node structure
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new node
node_t* create_node(int key) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert_node(node_t *root, int key) {
    if (root == NULL) {
        root = create_node(key);
    } else if (key < root->key) {
        insert_node(root->left, key);
    } else if (key > root->key) {
        insert_node(root->right, key);
    }
}

// Function to search for a node in the binary search tree
bool search_node(node_t *root, int key) {
    if (root == NULL) {
        return false;
    } else if (key == root->key) {
        return true;
    } else if (key < root->key) {
        return search_node(root->left, key);
    } else {
        return search_node(root->right, key);
    }
}

// Function to delete a node from the binary search tree
void delete_node(node_t *root, int key) {
    if (root == NULL) {
        return;
    } else if (key == root->key) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left != NULL && root->right == NULL) {
            node_t *temp = root->left;
            free(root);
            root = temp;
        } else if (root->left == NULL && root->right != NULL) {
            node_t *temp = root->right;
            free(root);
            root = temp;
        } else {
            node_t *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->key = temp->key;
            delete_node(root->right, temp->key);
        }
    } else if (key < root->key) {
        delete_node(root->left, key);
    } else {
        delete_node(root->right, key);
    }
}

int main() {
    node_t *root = NULL;

    // Insert nodes
    insert_node(root, 10);
    insert_node(root, 5);
    insert_node(root, 15);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 12);

    // Search for a node
    if (search_node(root, 7)) {
        printf("Found node with key 7\n");
    } else {
        printf("Node with key 7 not found\n");
    }

    // Delete a node
    delete_node(root, 10);

    // Search for a node again
    if (search_node(root, 10)) {
        printf("Found node with key 10\n");
    } else {
        printf("Node with key 10 not found\n");
    }

    return 0;
}