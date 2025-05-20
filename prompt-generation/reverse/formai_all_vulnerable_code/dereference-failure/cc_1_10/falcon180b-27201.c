//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define node structure
typedef struct node {
    char data[MAX_SIZE];
    int count;
    struct node *left;
    struct node *right;
} Node;

// Define tree structure
Node *tree = NULL;

// Create a new node
Node *createNode(char *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->data, data);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the tree
void insertNode(Node *node, char *data) {
    if (node == NULL) {
        node = createNode(data);
    } else if (strcmp(node->data, data) < 0) {
        insertNode(node->right, data);
    } else {
        insertNode(node->left, data);
    }
    node->count++;
}

// Search for a node in the tree
Node *searchNode(Node *node, char *data) {
    if (node == NULL || strcmp(node->data, data) == 0) {
        return node;
    } else if (strcmp(node->data, data) < 0) {
        return searchNode(node->right, data);
    } else {
        return searchNode(node->left, data);
    }
}

// Print the tree
void printTree(Node *node) {
    if (node == NULL) {
        return;
    } else {
        printTree(node->right);
        printf("%s: %d\n", node->data, node->count);
        printTree(node->left);
    }
}

int main() {
    char data[MAX_SIZE];
    Node *root = NULL;

    // Create a new node
    root = createNode("root");

    // Insert nodes into the tree
    insertNode(root, "child1");
    insertNode(root, "child2");
    insertNode(root, "child3");

    // Print the tree
    printf("Binary search tree:\n");
    printTree(root);

    return 0;
}