//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
/*
 * Binary search tree example program
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(struct node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else {
        if (data < root->data) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
    }
}

void print_inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

void print_preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node *root = NULL;
    int data;
    while (scanf("%d", &data) == 1) {
        insert(root, data);
    }
    print_inorder(root);
    printf("\n");
    print_preorder(root);
    printf("\n");
    print_postorder(root);
    printf("\n");
    return 0;
}