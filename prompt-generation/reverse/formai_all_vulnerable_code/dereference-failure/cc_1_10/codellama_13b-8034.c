//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: paranoid
// Binary search tree program in a paranoid style
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    } else {
        printf("Error: data already exists in the tree.\n");
        return root;
    }
    return root;
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    node *root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 2);
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 8);
    inorder_traversal(root);
    printf("\n");
    return 0;
}