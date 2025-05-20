//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Node struct for a binary tree
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new Node with a given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a Node in a binary tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) { // If the tree is empty
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to print the binary tree in ascending order
void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->value);
        printTree(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int input;

    printf("Enter values to insert (enter -1 to stop):\n");

    // Prompt user to enter values to insert
    do {
        scanf("%d", &input); // Read input value
        if (input != -1) {
            root = insertNode(root, input); // Insert Node with input value
        }
    } while (input != -1); // Repeat until user enters -1

    printf("\nBinary tree representation in ascending order:\n");
    printTree(root); // Print the binary tree in ascending order

    return 0;
}