//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a struct for each node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Helper function to insert a value into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Helper function to print the tree in order
void print_in_order(Node* root) {
    if (root!= NULL) {
        print_in_order(root->left);
        printf("%d ", root->data);
        print_in_order(root->right);
    }
}

// Helper function to search for a value in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Main function to test the tree operations
int main() {
    Node* root = NULL;

    // Insert some values into the tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print the tree in order
    printf("Tree in order: ");
    print_in_order(root);
    printf("\n");

    // Search for a value in the tree
    Node* result = search(root, 6);
    if (result!= NULL) {
        printf("Value %d found in the tree\n", result->data);
    } else {
        printf("Value %d not found in the tree\n", 9);
    }

    return 0;
}