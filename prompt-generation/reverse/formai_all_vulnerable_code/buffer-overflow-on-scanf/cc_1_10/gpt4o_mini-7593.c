//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the binary tree
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

// Function to print the tree structure
void printTree(Node* root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    printf("%*s%d\n", level * 4, "", root->data);
    printTree(root->left, level + 1);
}

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to display the menu
void displayMenu() {
    printf("\nBinary Tree Visualization Menu:\n");
    printf("1. Insert Node\n");
    printf("2. Show Tree Structure\n");
    printf("3. In-order Traversal\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the tree.\n", data);
                break;
            case 2:
                printf("Current Tree Structure:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("In-order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}