//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
    #include <stdlib.h>

    struct Node {
        int key;
        struct Node *left;
        struct Node *right;
    };

    struct Node* createNode(int key) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    struct Node* insertNode(struct Node* root, int key) {
        if (root == NULL) {
            return createNode(key);
        }

        if (key < root->key) {
            root->left = insertNode(root->left, key);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key);
        }

        return root;
    }

    int findNode(struct Node* root, int key) {
        if (root == NULL) {
            return 0;
        }

        if (root->key == key) {
            return 1;
        }

        if (key < root->key) {
            return findNode(root->left, key);
        } else {
            return findNode(root->right, key);
        }
    }

    int main() {
        struct Node* root = NULL;

        // Insert nodes
        root = insertNode(root, 10);
        root = insertNode(root, 20);
        root = insertNode(root, 30);
        root = insertNode(root, 40);
        root = insertNode(root, 50);

        // Search for a node
        int key = 20;
        if (findNode(root, key)) {
            printf("Key found: %d\n", key);
        } else {
            printf("Key not found: %d\n", key);
        }

        // Search for a node that doesn't exist
        key = 25;
        if (findNode(root, key)) {
            printf("Key found: %d\n", key);
        } else {
            printf("Key not found: %d\n", key);
        }

        return 0;
    }