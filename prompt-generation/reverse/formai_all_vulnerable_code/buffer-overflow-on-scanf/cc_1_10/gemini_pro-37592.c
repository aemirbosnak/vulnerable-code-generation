//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
    struct _tree *left;
    struct _tree *right;
    int data;
} tree;

tree *insert(tree *root, int data) {
    if (root == NULL) {
        root = (tree *)malloc(sizeof(tree));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

tree *search(tree *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    tree *root = NULL;
    int n, i, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    tree *result = search(root, x);
    if (result == NULL) {
        printf("Element not found\n");
    } else {
        printf("Element found: %d\n", result->data);
    }
    return 0;
}