//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node with the given data into the tree
void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Search for a node with the given data in the tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print the tree in a sorted order
void printTree(struct Node* root) {
    if (root!= NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main() {
    // Create a new tree with some nodes
    struct Node* root = NULL;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Print the tree in a sorted order
    printf("Sorted tree:\n");
    printTree(root);
    printf("\n");

    // Search for a node with the given data in the tree
    struct Node* node = search(root, 6);
    if (node!= NULL) {
        printf("Found node with data: %d\n", node->data);
    } else {
        printf("Node not found!\n");
    }

    return 0;
}