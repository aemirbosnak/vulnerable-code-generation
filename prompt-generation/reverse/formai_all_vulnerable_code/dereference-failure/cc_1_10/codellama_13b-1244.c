//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
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

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = new_node(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

int search(node *root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void destroy_tree(node *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int main() {
    node *root = NULL;
    int i;
    int data[10] = {5, 8, 2, 1, 6, 3, 9, 4, 7};

    for (i = 0; i < 10; i++) {
        insert(&root, data[i]);
    }

    printf("Searching for 6: %d\n", search(root, 6));
    printf("Searching for 10: %d\n", search(root, 10));

    destroy_tree(root);

    return 0;
}