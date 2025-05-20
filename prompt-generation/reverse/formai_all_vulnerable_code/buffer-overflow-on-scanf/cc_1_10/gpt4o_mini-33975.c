//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) 
        node->left = insert(node->left, data);
    else if (data > node->data) 
        node->right = insert(node->right, data);
    return node;
}

// Function to print the binary tree visually in 2D format
void printTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 10; // Increase distance between levels

    printTree(root->right, space); // Process right subtree

    printf("\n");
    for (int i = 10; i < space; i++) printf(" "); // Indentation
    printf("%d\n", root->data); // Print current node

    printTree(root->left, space); // Process left subtree
}

// Function to free the binary tree
void freeTree(struct Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main function to execute the program
int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("Binary Tree Visualization\n");
        printf("1. Insert Node\n");
        printf("2. Print Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Binary Tree:\n");
                printTree(root, 0); // Start with space of 0
                printf("\n");
                break;
            case 3:
                freeTree(root); // Free allocated memory
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}