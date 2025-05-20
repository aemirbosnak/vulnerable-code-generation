//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct node {
    int value;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given value
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a value into the binary search tree
struct node* insert_value(struct node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert_value(root->left, value);
    } else if (value > root->value) {
        root->right = insert_value(root->right, value);
    }

    return root;
}

// Function to search for a value in the binary search tree
struct node* search_value(struct node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search_value(root->left, value);
    } else {
        return search_value(root->right, value);
    }
}

// Function to print the values in the binary search tree in order
void print_values(struct node* root) {
    if (root == NULL) {
        return;
    }

    print_values(root->left);
    printf("%d ", root->value);
    print_values(root->right);
}

// Main function to test the binary search tree functions
int main() {
    struct node* root = NULL;

    // Insert some values into the binary search tree
    root = insert_value(root, 10);
    root = insert_value(root, 20);
    root = insert_value(root, 30);
    root = insert_value(root, 40);
    root = insert_value(root, 50);

    // Print the values in the binary search tree
    printf("Values in order:\n");
    print_values(root);

    // Search for a value in the binary search tree
    struct node* found_node = search_value(root, 30);
    if (found_node!= NULL) {
        printf("Found value %d\n", found_node->value);
    } else {
        printf("Value not found\n");
    }

    return 0;
}