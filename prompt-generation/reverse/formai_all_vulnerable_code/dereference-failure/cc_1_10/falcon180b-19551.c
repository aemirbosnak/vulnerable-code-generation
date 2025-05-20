//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node with the given data into the tree
Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Search for a node with the given data in the tree
Node* search_node(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Print the tree in a medieval style
void print_tree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;
    print_tree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("+--");

    if (root->left == NULL && root->right == NULL) {
        printf("\\n");
    } else if (root->left == NULL) {
        printf(" \\n");
    } else if (root->right == NULL) {
        printf("  \\n");
    } else {
        printf("   \\n");
    }
}

// Main function to test the tree operations
int main() {
    Node* root = NULL;

    // Insert some nodes into the tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Print the tree
    printf("The noble tree of integers:\n");
    print_tree(root, 0);

    return 0;
}