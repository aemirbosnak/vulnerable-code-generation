//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if ((*root)->data > data) {
        insert(&((*root)->left), data);
    } else if ((*root)->data < data) {
        insert(&((*root)->right), data);
    }
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(&root, data);
    }
    inorder(root);
    return 0;
}