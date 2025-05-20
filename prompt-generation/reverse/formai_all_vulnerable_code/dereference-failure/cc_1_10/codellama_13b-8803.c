//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: happy
/*
 * Happy Binary Search Tree Program
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* create_node(int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void preorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
}

int main() {
    struct node *root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 2);
    root = insert_node(root, 4);
    root = insert_node(root, 6);
    root = insert_node(root, 8);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}