//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: synchronous
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

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node *search_node(node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    node *root = NULL;
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("Inorder traversal: ");
    print_tree(root);
    printf("\n");
    printf("Enter the data to search: ");
    scanf("%d", &data);
    node *found_node = search_node(root, data);
    if (found_node == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found with data %d\n", found_node->data);
    }
    free_tree(root);
    return 0;
}