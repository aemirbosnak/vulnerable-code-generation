//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: peaceful
// Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Creates a new BSTNode
BSTNode* createNode(int data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the BST
void insert(BSTNode** root, int data) {
    // If the tree is empty
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    // Find the correct location for the node
    BSTNode* current = *root;
    while (current != NULL) {
        if (data < current->data) {
            // Insert into the left subtree
            if (current->left == NULL) {
                current->left = createNode(data);
                return;
            }
            current = current->left;
        } else {
            // Insert into the right subtree
            if (current->right == NULL) {
                current->right = createNode(data);
                return;
            }
            current = current->right;
        }
    }
}

// Find the node with the given data
BSTNode* find(BSTNode* root, int data) {
    while (root != NULL) {
        if (data == root->data) {
            return root;
        } else if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// Print the BST in order
void printInOrder(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Print the BST in pre order
void printPreOrder(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Print the BST in post order
void printPostOrder(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Free the BST
void freeBST(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    // Create a BST
    BSTNode* root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 15);

    // Print the BST
    printf("In order: ");
    printInOrder(root);
    printf("\n");

    printf("Pre order: ");
    printPreOrder(root);
    printf("\n");

    printf("Post order: ");
    printPostOrder(root);
    printf("\n");

    // Free the BST
    freeBST(root);

    return 0;
}