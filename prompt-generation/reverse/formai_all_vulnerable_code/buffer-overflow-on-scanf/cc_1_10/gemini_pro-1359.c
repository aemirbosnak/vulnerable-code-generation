//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int search_node(struct node *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
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
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    printf("Enter the data value to search: ");
    scanf("%d", &data);
    if (search_node(root, data)) {
        printf("The data value is found in the binary search tree.\n");
    } else {
        printf("The data value is not found in the binary search tree.\n");
    }
    return 0;
}