//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: light-weight
/*
 * C Binary Search Tree Example Program
 *
 * A binary search tree is a data structure in which each node has at most two
 * children, one left child and one right child. Each node in the left subtree
 * has a key value less than the node's key value, and each node in the right
 * subtree has a key value greater than the node's key value.
 *
 * In this example, we will create a binary search tree that stores integers.
 * We will be able to insert, search, and delete nodes from the tree.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure
 */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

/*
 * Create a new node with the given key
 */
Node* createNode(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * Insert a new node with the given key into the tree
 */
void insert(Node **root, int key) {
    // Check if the root is NULL
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    // Check if the key is less than the root
    if (key < (*root)->key) {
        // Insert the node into the left subtree
        insert(&(*root)->left, key);
    } else {
        // Insert the node into the right subtree
        insert(&(*root)->right, key);
    }
}

/*
 * Search for a node with the given key in the tree
 */
Node* search(Node *root, int key) {
    // Check if the root is NULL
    if (root == NULL) {
        return NULL;
    }

    // Check if the key is equal to the root
    if (key == root->key) {
        return root;
    }

    // Check if the key is less than the root
    if (key < root->key) {
        // Search the left subtree
        return search(root->left, key);
    } else {
        // Search the right subtree
        return search(root->right, key);
    }
}

/*
 * Delete a node with the given key from the tree
 */
void delete(Node **root, int key) {
    // Check if the root is NULL
    if (*root == NULL) {
        return;
    }

    // Check if the key is equal to the root
    if (key == (*root)->key) {
        // If the root has no children, delete the root
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return;
        }

        // If the root has one child, replace the root with the child
        if ((*root)->left == NULL) {
            Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        } else if ((*root)->right == NULL) {
            Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        }

        // If the root has two children, find the inorder successor and delete it
        Node *temp = (*root)->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        (*root)->key = temp->key;
        delete(&(*root)->right, temp->key);
        return;
    }

    // Check if the key is less than the root
    if (key < (*root)->key) {
        // Delete the node from the left subtree
        delete(&(*root)->left, key);
    } else {
        // Delete the node from the right subtree
        delete(&(*root)->right, key);
    }
}

int main() {
    Node *root = NULL;

    // Insert some nodes into the tree
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 18);
    insert(&root, 20);
    insert(&root, 25);

    // Search for a node with the key 15
    Node *node = search(root, 15);
    if (node != NULL) {
        printf("Node with key 15 found: %d\n", node->key);
    } else {
        printf("Node with key 15 not found\n");
    }

    // Delete the node with the key 20
    delete(&root, 20);

    // Search for a node with the key 20
    node = search(root, 20);
    if (node != NULL) {
        printf("Node with key 20 found: %d\n", node->key);
    } else {
        printf("Node with key 20 not found\n");
    }

    return 0;
}