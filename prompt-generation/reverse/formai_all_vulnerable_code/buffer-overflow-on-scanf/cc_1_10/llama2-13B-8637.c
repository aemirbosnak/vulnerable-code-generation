//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node representing a binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new binary search tree
struct BSTNode* createBST(void) {
    struct BSTNode* root = NULL;
    int data;

    do {
        printf("Enter a key (or -1 to stop): ");
        scanf("%d", &data);

        // Create a new node with the entered key
        struct BSTNode* newNode = (struct BSTNode*) malloc(sizeof(struct BSTNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        // Add the new node to the tree
        if (root == NULL) {
            root = newNode;
        } else {
            if (data < root->data) {
                root->left = newNode;
            } else if (data > root->data) {
                root->right = newNode;
            }
        }

    } while (data != -1);

    return root;
}

// Function to search for a key in the binary search tree
struct BSTNode* searchBST(struct BSTNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        return searchBST(root->left, key);
    } else if (key > root->data) {
        return searchBST(root->right, key);
    } else {
        return root;
    }
}

int main(void) {
    struct BSTNode* root = createBST();

    // Test the binary search tree
    printf("Binary search tree:\n");
    searchBST(root, 10);
    searchBST(root, 20);
    searchBST(root, 30);

    return 0;
}