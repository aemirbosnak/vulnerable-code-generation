//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: synchronous
/*
 * Example program to demonstrate binary search tree in C.
 *
 * Uses synchronous style.
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a binary search tree.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure to represent a binary search tree.
struct BinarySearchTree {
    struct Node* root;
};

// Function to create a new node.
struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in a binary search tree.
void insert(struct BinarySearchTree* tree, int data) {
    struct Node* node = createNode(data);
    if (tree->root == NULL) {
        tree->root = node;
    } else {
        struct Node* curr = tree->root;
        struct Node* parent = NULL;
        while (curr != NULL) {
            parent = curr;
            if (data < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (data < parent->data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
}

// Function to search for a node in a binary search tree.
int search(struct BinarySearchTree* tree, int data) {
    struct Node* curr = tree->root;
    while (curr != NULL) {
        if (data == curr->data) {
            return 1;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return 0;
}

// Function to delete a node from a binary search tree.
void delete(struct BinarySearchTree* tree, int data) {
    struct Node* curr = tree->root;
    struct Node* parent = NULL;
    while (curr != NULL) {
        if (data == curr->data) {
            if (curr->left == NULL && curr->right == NULL) {
                // Node has no children, simply delete it.
                if (parent != NULL) {
                    if (parent->left == curr) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                } else {
                    tree->root = NULL;
                }
                free(curr);
                return;
            } else if (curr->left != NULL && curr->right == NULL) {
                // Node has left child only, replace it with left child.
                if (parent != NULL) {
                    if (parent->left == curr) {
                        parent->left = curr->left;
                    } else {
                        parent->right = curr->left;
                    }
                } else {
                    tree->root = curr->left;
                }
                free(curr);
                return;
            } else if (curr->left == NULL && curr->right != NULL) {
                // Node has right child only, replace it with right child.
                if (parent != NULL) {
                    if (parent->left == curr) {
                        parent->left = curr->right;
                    } else {
                        parent->right = curr->right;
                    }
                } else {
                    tree->root = curr->right;
                }
                free(curr);
                return;
            } else {
                // Node has two children, replace it with the smallest value in its right subtree.
                struct Node* smallest = curr->right;
                struct Node* smallestParent = curr;
                while (smallest->left != NULL) {
                    smallestParent = smallest;
                    smallest = smallest->left;
                }
                curr->data = smallest->data;
                if (smallestParent->left == smallest) {
                    smallestParent->left = NULL;
                } else {
                    smallestParent->right = NULL;
                }
                free(smallest);
                return;
            }
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

// Function to traverse the binary search tree in preorder.
void preorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main() {
    struct BinarySearchTree tree;
    tree.root = NULL;
    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 7);
    insert(&tree, 1);
    insert(&tree, 4);
    insert(&tree, 6);
    insert(&tree, 8);
    insert(&tree, 2);
    printf("Preorder traversal: ");
    preorderTraversal(tree.root);
    printf("\n");
    printf("Searching for 1: %d\n", search(&tree, 1));
    printf("Searching for 10: %d\n", search(&tree, 10));
    delete(&tree, 1);
    printf("Preorder traversal after deletion: ");
    preorderTraversal(tree.root);
    printf("\n");
    return 0;
}