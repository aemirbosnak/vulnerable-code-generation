//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 10
#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a new node into the binary tree
Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to create a tree
Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (tree) {
        tree->root = NULL;
    }
    return tree;
}

// Function to visualize the binary tree
void printTree(Node* root, int level, int indentSpace) {
    if (root != NULL) {
        printTree(root->right, level + 1, indentSpace);
        printf("\n");
        if (level > 0) {
            for (int i = 0; i < indentSpace; i++) {
                printf(" ");
            }
        }
        printf("%d\n", root->data);
        printTree(root->left, level + 1, indentSpace);
    }
}

void freeTree(Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    Tree* tree = createTree();
    if (tree == NULL) {
        fprintf(stderr, "Failed to create tree\n");
        return 1;
    }

    int choice;
    int value;

    do {
        printf("\n--- Binary Tree Visualization ---\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node value to insert: ");
                scanf("%d", &value);
                tree->root = insert(tree->root, value);
                break;
            case 2:
                printf("Current Tree Structure:\n");
                printTree(tree->root, 0, 10);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 0);

    freeTree(tree->root);
    free(tree);
    return 0;
}