//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
/*
 * A unique C Binary search trees example program in a Dennis Ritchie style
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *new_node(int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *insert(node *root, int data) {
    if (root == NULL) {
        return new_node(data);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    inorder(root);
    printf("\n");

    return 0;
}