//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    node *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert_node(&root, data);
    }
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\nPreorder traversal: ");
    preorder_traversal(root);
    printf("\nPostorder traversal: ");
    postorder_traversal(root);
    return 0;
}