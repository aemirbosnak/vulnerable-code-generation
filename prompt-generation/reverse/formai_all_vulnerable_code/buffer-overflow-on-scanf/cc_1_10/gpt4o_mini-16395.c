//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a Node in the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to display the BST structure visually
void displayTree(Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    displayTree(root->right, space); // Visit right subtree

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" "); // Print space
    }
    printf("%d\n", root->data); // Print the current node

    displayTree(root->left, space); // Visit left subtree
}

// Driver code
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree (BST) Visualization\n");
        printf("1. Insert Element\n");
        printf("2. Display Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;
            case 2:
                printf("Current BST structure:\n");
                displayTree(root, 0);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}