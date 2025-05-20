//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        root = malloc(sizeof(struct node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(struct node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        return 1;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 30);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Searching for 15: %d\n", search(root, 15));
    printf("Searching for 30: %d\n", search(root, 30));
    printf("Searching for 25: %d\n", search(root, 25));
    printf("Searching for 10: %d\n", search(root, 10));
    printf("Searching for 5: %d\n", search(root, 5));
    return 0;
}