//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
typedef struct {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node with the given data
node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error! ");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node with the given data into the binary search tree
node* insert_node(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to traverse the binary search tree in in-order, pre-order, and post-order
void in_order_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

void pre_order_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void post_order_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

// Main function to test the binary search tree operations
int main() {
    node* root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 17);

    printf("In-order traversal: ");
    in_order_traversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    pre_order_traversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order_traversal(root);
    printf("\n");

    return 0;
}