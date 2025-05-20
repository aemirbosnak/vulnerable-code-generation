//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
/*
 * Binary Search Tree Example Program
 *
 * A program that demonstrates the use of a binary search tree data structure in C.
 *
 * The program prompts the user to input a series of integers, which are then inserted
 * into a binary search tree. The tree is then traversed and the integers are printed
 * in sorted order.
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the binary search tree
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Define a function to create a new node
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Define a function to insert a new node into the binary search tree
void insert_node(struct node *root, int value) {
    if (root == NULL) {
        root = create_node(value);
        return;
    }

    if (value < root->value) {
        if (root->left == NULL) {
            root->left = create_node(value);
        } else {
            insert_node(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = create_node(value);
        } else {
            insert_node(root->right, value);
        }
    }
}

// Define a function to traverse the binary search tree and print the values
void traverse_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    traverse_tree(root->left);
    printf("%d ", root->value);
    traverse_tree(root->right);
}

int main() {
    struct node *root = NULL;

    // Insert some integers into the binary search tree
    insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 2);
    insert_node(root, 4);
    insert_node(root, 1);

    // Traverse the binary search tree and print the values
    traverse_tree(root);

    return 0;
}