//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Structure for the Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to print the tree in a structured format
void printTree(Node* root, int space) {
    if (root == NULL) return;
    
    space += 10; // Increase distance between levels

    printTree(root->right, space); // Process right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" "); // Print spaces for formatting
    }
    printf("%d\n", root->data); // Print the current node's data

    printTree(root->left, space); // Then process left child
}

// Function to free the allocated memory for the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the binary tree
int main() {
    Node* root = NULL;
    int choice, element;

    // Menu for user interaction
    do {
        printf("\nBinary Tree Visualization\n");
        printf("1. Insert Element\n");
        printf("2. Display Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("%d inserted into the tree.\n", element);
                break;

            case 2:
                printf("Current Binary Tree:\n");
                printTree(root, 0);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    freeTree(root); // Free the allocated memory before exiting
    return 0;
}