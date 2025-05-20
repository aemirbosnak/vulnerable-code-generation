//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data into the tree
void insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

// Search for a node with the given data in the tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Print the tree in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function to test the tree implementation
int main() {
    // Create a new tree with some sample data
    Node* root = NULL;
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);

    // Print the tree in order traversal
    printf("Tree in order traversal:\n");
    printTree(root);
    printf("\n");

    // Search for a node with the given data
    Node* foundNode = searchNode(root, 30);
    if (foundNode!= NULL) {
        printf("Node found with data: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}