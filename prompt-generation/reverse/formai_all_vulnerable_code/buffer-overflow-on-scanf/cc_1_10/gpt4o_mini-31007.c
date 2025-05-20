//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a struct for Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct Node* insert(struct Node* root, int data) {
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

// Function to print spaces for indentation
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print the binary tree in a hierarchical format
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10; // Increase distance between levels

    printTree(root->right, space);

    printf("\n");
    printSpaces(space - 10);
    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Function to free the tree
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Tree Visualization Menu\n");
        printf("1. Insert a Node\n");
        printf("2. Visualize Tree\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the tree.\n", value);
                break;
            case 2:
                printf("\nBinary Tree Visualization:\n");
                printTree(root, 0);
                break;
            case 3:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}