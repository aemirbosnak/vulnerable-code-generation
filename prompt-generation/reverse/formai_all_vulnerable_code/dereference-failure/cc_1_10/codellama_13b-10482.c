//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: introspective
/*
 * Binary Search Tree Program
 *
 * This program demonstrates the use of binary search trees in C.
 * It prompts the user to enter a series of numbers, and then
 * allows the user to search for specific numbers in the tree.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Structure to represent a node in the binary search tree.
 */
struct node {
    int value;
    struct node *left;
    struct node *right;
};

/*
 * Function to create a new node with the given value.
 */
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/*
 * Function to insert a node into the binary search tree.
 */
void insert(struct node *root, int value) {
    if (root == NULL) {
        root = create_node(value);
    } else if (value < root->value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

/*
 * Function to search for a value in the binary search tree.
 */
struct node *search(struct node *root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (root->value == value) {
        return root;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

/*
 * Function to print the contents of the binary search tree.
 */
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    int value;

    while (1) {
        printf("Enter a value to insert: ");
        scanf("%d", &value);
        insert(root, value);
        printf("Tree after insertion: ");
        print_tree(root);
        printf("\n");
    }

    return 0;
}