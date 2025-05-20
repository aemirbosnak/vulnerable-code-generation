//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: lively
/*
 * A unique C Binary search trees example program
 *
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int find(Node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        return 1;
    }
    if (value < root->value) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d\n", root->value);
    printTree(root->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);

    printf("Tree before search:\n");
    printTree(root);

    int value = 1;
    if (find(root, value)) {
        printf("Value %d found in the tree\n", value);
    } else {
        printf("Value %d not found in the tree\n", value);
    }

    value = 8;
    if (find(root, value)) {
        printf("Value %d found in the tree\n", value);
    } else {
        printf("Value %d not found in the tree\n", value);
    }

    return 0;
}