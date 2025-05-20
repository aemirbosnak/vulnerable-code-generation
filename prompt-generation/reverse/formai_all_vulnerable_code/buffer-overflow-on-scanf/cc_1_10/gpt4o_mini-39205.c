//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value in the binary tree
Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to visualize the binary tree
void visualizeTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
    
    // Increase distance between levels
    space += 4;

    // Process right child first
    visualizeTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    visualizeTree(root->left, space);
}

// Function to free the binary tree
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    Node *root = NULL;
    int choice, value;

    printf("Binary Tree Visualization Program\n");
    printf("1. Insert value\n");
    printf("2. Visualize Tree\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
            case 2:
                printf("Visualizing Binary Tree:\n");
                visualizeTree(root, 0);
                break;
            case 3:
                freeTree(root);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
}