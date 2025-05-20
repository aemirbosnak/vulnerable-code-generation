//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    struct node *current = *root;
    while (1) {
        if (current->data < data) {
            if (current->right == NULL) {
                current->right = new_node;
                break;
            } else {
                current = current->right;
            }
        } else {
            if (current->left == NULL) {
                current->left = new_node;
                break;
            } else {
                current = current->left;
            }
        }
    }
}

int search(struct node *root, int data) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    } else if (root->data < data) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

int main() {
    struct node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);

    printf("Searching for 40: %d\n", search(root, 40));
    printf("Searching for 60: %d\n", search(root, 60));

    return 0;
}