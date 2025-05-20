//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
// Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

// Function to create a new node
node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the binary search tree
void insert_node(node* root, int value) {
    if (root == NULL) {
        root = create_node(value);
        return;
    }
    if (value < root->value) {
        insert_node(root->left, value);
    } else if (value > root->value) {
        insert_node(root->right, value);
    }
}

// Function to search a value in the binary search tree
node* search_node(node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        return search_node(root->left, value);
    } else if (value > root->value) {
        return search_node(root->right, value);
    } else {
        return root;
    }
}

// Function to print the binary search tree
void print_tree(node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

int main() {
    // Create a new binary search tree
    node* root = NULL;

    // Insert some values in the binary search tree
    insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 1);
    insert_node(root, 4);
    insert_node(root, 2);

    // Search for a value in the binary search tree
    node* found = search_node(root, 4);
    if (found != NULL) {
        printf("Found %d\n", found->value);
    } else {
        printf("Not found\n");
    }

    // Print the binary search tree
    print_tree(root);

    return 0;
}