//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with the given data
Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a node with the given data into the tree
void insert_node(Node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        insert_node(root->left, data);
    } else {
        insert_node(root->right, data);
    }
}

// Search for a node with the given data in the tree
Node *search_node(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print the tree in order traversal
void print_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

// Main function
int main() {
    Node *root = NULL;

    // Insert nodes into the tree
    insert_node(root, 10);
    insert_node(root, 20);
    insert_node(root, 30);
    insert_node(root, 40);
    insert_node(root, 50);

    // Print the tree in order traversal
    printf("Tree in order traversal:\n");
    print_tree(root);

    return 0;
}