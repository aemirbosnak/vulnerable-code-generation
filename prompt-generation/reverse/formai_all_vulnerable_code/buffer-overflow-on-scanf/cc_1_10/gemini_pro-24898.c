//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: romantic
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
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    node *root = NULL;
    int data;
    printf("Enter the data for the binary search tree (-1 to stop): ");
    while (scanf("%d", &data) == 1 && data != -1) {
        root = insert_node(root, data);
    }
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    printf("Enter the data to search for: ");
    scanf("%d", &data);
    node *found_node = search_node(root, data);
    if (found_node == NULL) {
        printf("The data was not found in the binary search tree.\n");
    } else {
        printf("The data was found in the binary search tree.\n");
    }
    return 0;
}