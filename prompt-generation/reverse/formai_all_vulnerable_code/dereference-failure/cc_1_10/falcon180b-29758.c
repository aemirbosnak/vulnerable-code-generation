//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: imaginative
/* This program creates a visualization of a binary search tree using ASCII characters. */

#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a binary search tree node. */
typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
} TreeNode;

/* Function to create a new binary search tree node. */
TreeNode* create_node(int data) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Function to insert a value into the binary search tree. */
void insert_value(TreeNode* root, int value) {
    if (root == NULL) {
        root = create_node(value);
    } else if (value < root->data) {
        insert_value(root->left, value);
    } else {
        insert_value(root->right, value);
    }
}

/* Function to print the binary search tree in a visually appealing way. */
void print_tree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);

    print_tree(root->left, space);
}

/* Main function to test the binary search tree functions. */
int main() {
    TreeNode* root = NULL;

    /* Insert values into the binary search tree. */
    insert_value(root, 50);
    insert_value(root, 30);
    insert_value(root, 20);
    insert_value(root, 40);
    insert_value(root, 70);
    insert_value(root, 60);
    insert_value(root, 80);

    /* Print the binary search tree. */
    printf("Binary Search Tree:\n");
    print_tree(root, 0);

    return 0;
}