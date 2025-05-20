//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
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

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 30);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 25);
    root = insert_node(root, 35);
    root = insert_node(root, 45);
    print_tree(root);
    return 0;
}