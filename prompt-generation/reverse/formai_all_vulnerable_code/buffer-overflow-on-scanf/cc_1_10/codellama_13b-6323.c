//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insertNode(&(*root)->right, data);
    }
}

void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    Node *root = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&root, data);
    }

    inorderTraversal(root);
    printf("\n");

    return 0;
}