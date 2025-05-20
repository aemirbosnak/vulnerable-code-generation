//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: modular
/*
 * binary_search_tree.c
 *
 * A modular implementation of a binary search tree in C.
 *
 * Usage:
 *
 *    1. Create a new tree by calling the create_tree function.
 *    2. Insert new nodes by calling the insert_node function.
 *    3. Search for a node by calling the search_node function.
 *    4. Delete a node by calling the delete_node function.
 *    5. Destroy the tree by calling the destroy_tree function.
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Tree structure
typedef struct tree {
    node_t *root;
} tree_t;

// Function prototypes
node_t* create_node(int data);
tree_t* create_tree();
void insert_node(tree_t *tree, node_t *node);
node_t* search_node(tree_t *tree, int data);
void delete_node(tree_t *tree, node_t *node);
void destroy_tree(tree_t *tree);

// Create a new node
node_t* create_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new tree
tree_t* create_tree() {
    tree_t *tree = malloc(sizeof(tree_t));
    tree->root = NULL;
    return tree;
}

// Insert a new node into the tree
void insert_node(tree_t *tree, node_t *node) {
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    node_t *current = tree->root;
    while (current != NULL) {
        if (node->data < current->data) {
            if (current->left == NULL) {
                current->left = node;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

// Search for a node in the tree
node_t* search_node(tree_t *tree, int data) {
    if (tree->root == NULL) {
        return NULL;
    }

    node_t *current = tree->root;
    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

// Delete a node from the tree
void delete_node(tree_t *tree, node_t *node) {
    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        delete_node(tree, node->left);
    }
    if (node->right != NULL) {
        delete_node(tree, node->right);
    }

    if (node == tree->root) {
        tree->root = NULL;
    } else {
        node_t *parent = search_node(tree, node->data);
        if (parent != NULL) {
            if (node == parent->left) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
    }
    free(node);
}

// Destroy the tree
void destroy_tree(tree_t *tree) {
    if (tree->root != NULL) {
        delete_node(tree, tree->root);
    }
    free(tree);
}

int main() {
    tree_t *tree = create_tree();

    // Insert nodes
    insert_node(tree, create_node(1));
    insert_node(tree, create_node(2));
    insert_node(tree, create_node(3));
    insert_node(tree, create_node(4));
    insert_node(tree, create_node(5));

    // Search for a node
    node_t *node = search_node(tree, 3);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    delete_node(tree, node);

    // Destroy the tree
    destroy_tree(tree);

    return 0;
}