//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the binary search tree
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Recursive function to search for a value in the binary search tree
Node* search(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to perform in-order traversal of the tree
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Function to delete the tree and free memory
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

// Function to display a menu
void displayMenu() {
    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Insert an element\n");
    printf("2. Search for an element\n");
    printf("3. Display in-order traversal\n");
    printf("4. Exit\n");
    printf("--------------------------------\n");
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;
    Node* searchResult;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted into the tree.\n", value);
                break;

            case 2:
                printf("Enter a value to search: ");
                scanf("%d", &value);
                searchResult = search(root, value);
                if (searchResult != NULL) {
                    printf("Value %d found in the tree!\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;

            case 3:
                printf("In-order traversal of the tree: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                deleteTree(root);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}