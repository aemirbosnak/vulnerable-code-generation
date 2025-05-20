//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: minimalist
/*
 * Binary Search Tree Example
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node(int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

node* search_node(node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data == root->data) {
        return root;
    }

    if (data <= root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void inorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

void delete_node(node* root) {
    if (root == NULL) {
        return;
    }

    delete_node(root->left);
    delete_node(root->right);
    free(root);
}

int main() {
    node* root = NULL;

    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
    root = insert_node(root, 2);
    root = insert_node(root, 4);
    root = insert_node(root, 6);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    delete_node(root);

    return 0;
}