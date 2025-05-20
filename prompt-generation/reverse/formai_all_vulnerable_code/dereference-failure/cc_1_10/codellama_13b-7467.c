//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: curious
/*
 * Binary search tree example program in a curious style
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(struct node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        insert_node(root->left, data);
    } else if (data > root->data) {
        insert_node(root->right, data);
    }
}

void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    insert_node(root, 10);
    insert_node(root, 20);
    insert_node(root, 30);
    insert_node(root, 40);
    insert_node(root, 50);
    print_tree(root);
    return 0;
}