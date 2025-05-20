//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the BST
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* new_node(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
void insert(struct node** root_ref, int data) {
    struct node* root = *root_ref;
    if (!root) {
        root = new_node(data);
        *root_ref = root;
    } else {
        if (data < root->data) {
            if (!root->left) {
                root->left = new_node(data);
            } else {
                insert(root->left, data);
            }
        } else {
            if (!root->right) {
                root->right = new_node(data);
            } else {
                insert(root->right, data);
            }
        }
    }
}

// Function to search for a node in the BST
struct node* search(struct node* root, int data) {
    if (!root) {
        return NULL;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to print the BST in a spiral format
void print_spiral(struct node* root) {
    if (!root) {
        return;
    }
    print_spiral(root->left);
    printf("%d ", root->data);
    print_spiral(root->right);
}

int main() {
    struct node* root = NULL;
    int data;

    // Create a BST with custom insertion and search functions
    printf("Enter nodes to add to the BST: ");
    while (scanf("%d", &data) == 1) {
        insert(&root, data);
    }

    // Search for a node in the BST
    printf("Enter a node to search for: ");
    scanf("%d", &data);
    struct node* found = search(root, data);
    if (found) {
        printf("Found %d at position %d\n", found->data, found->left == NULL ? 0 : 1);
    } else {
        printf("Not found\n");
    }

    // Print the BST in a spiral format
    printf("BST in spiral format: \n");
    print_spiral(root);

    return 0;
}