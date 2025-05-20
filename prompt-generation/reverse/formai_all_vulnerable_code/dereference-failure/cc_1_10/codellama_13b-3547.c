//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: real-life
/*
 * Program to create a unique C Binary search tree program
 * in a real-life style
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if ((*root)->data > data) {
        insert_node(&(*root)->left, data);
    } else if ((*root)->data < data) {
        insert_node(&(*root)->right, data);
    } else {
        return;
    }
}

int search_node(struct node *root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    }

    if (root->data > data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

int main() {
    struct node *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 20);
    insert_node(&root, 30);
    insert_node(&root, 40);
    insert_node(&root, 50);

    printf("%d\n", search_node(root, 30));
    printf("%d\n", search_node(root, 100));

    return 0;
}