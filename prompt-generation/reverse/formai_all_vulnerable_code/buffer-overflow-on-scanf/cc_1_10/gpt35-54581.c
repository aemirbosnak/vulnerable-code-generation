//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *create_node(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

struct node *search_node(struct node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return search_node(root->left, value);
    } else {
        return search_node(root->right, value);
    }
}

void print_tree(struct node *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->value);
        print_tree(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int n;
    printf("Enter number of elements to add in Binary Search Tree: ");
    scanf("%d", &n);

    printf("Enter %d integer values to add in Binary Search Tree:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert_node(root, x);
    }

    printf("Inorder traversal of Binary Search Tree: ");
    print_tree(root);

    printf("\nEnter value to search in Binary Search Tree: ");
    int search_value;
    scanf("%d", &search_value);
    if (search_node(root, search_value) == NULL) {
        printf("%d not found in Binary Search Tree.\n", search_value);
    } else {
        printf("%d found in Binary Search Tree.\n", search_value);
    }
    return 0;
}