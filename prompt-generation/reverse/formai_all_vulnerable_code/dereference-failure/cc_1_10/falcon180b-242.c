//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    char *data;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with the given data
Node *create_node(char *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node with the given data into the binary search tree
void insert_node(Node *root, char *data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (strcmp(data, root->data) < 0) {
        insert_node(root->left, data);
    } else {
        insert_node(root->right, data);
    }
}

// Search for a node with the given data in the binary search tree
Node *search_node(Node *root, char *data) {
    if (root == NULL || strcmp(data, root->data) == 0) {
        return root;
    } else if (strcmp(data, root->data) < 0) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Inorder traversal of the binary search tree
void inorder_traversal(Node *root) {
    if (root!= NULL) {
        inorder_traversal(root->left);
        printf("%s ", root->data);
        inorder_traversal(root->right);
    }
}

// Main function
int main() {
    Node *root = NULL;
    char *data = "apple";
    root = create_node(data);
    printf("Inserting %s\n", data);
    insert_node(root, "banana");
    insert_node(root, "cherry");
    printf("Searching for %s\n", "banana");
    Node *node = search_node(root, "banana");
    if (node!= NULL) {
        printf("Found %s\n", node->data);
    } else {
        printf("Not found\n");
    }
    printf("Inorder traversal:\n");
    inorder_traversal(root);
    printf("\n");
    return 0;
}