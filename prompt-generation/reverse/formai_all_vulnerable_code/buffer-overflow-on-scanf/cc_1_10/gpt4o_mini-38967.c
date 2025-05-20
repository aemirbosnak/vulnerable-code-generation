//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree recursively
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform in-order traversal and print the elements
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to visualize the tree structure
void visualizeTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;  // Increase distance between levels

    // Process right child first
    visualizeTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    visualizeTree(root->left, space);
}

// Driver program to demonstrate binary tree visualization
int main() {
    Node* root = NULL;
    int numNodes, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nIn-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("\nVisualizing the Binary Tree:\n");
    visualizeTree(root, 0);

    // Free the allocated memory (not shown for brevity)
    // A function would be needed to free the entire tree

    return 0;
}