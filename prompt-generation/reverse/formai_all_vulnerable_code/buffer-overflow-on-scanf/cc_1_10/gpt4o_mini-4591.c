//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Node structure for the Binary Search Tree
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new tree node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name);
    } else {
        root->right = insert(root->right, name);
    }

    return root;
}

// Function for in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s\n", root->name);
        inOrderTraversal(root->right);
    }
}

// Function to search a name in the BST
Node* search(Node* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

// Function to delete the entire BST
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

// Simulation function for a Cyberpunk style interaction
void cyberpunkInterface() {
    printf("~ Welcome to the Neon Net ~\n");
    printf("In this database, you can keep track of hackers, netrunners, and other shady characters.\n");
    printf("Commands:\n");
    printf("1. Insert a name\n");
    printf("2. Search for a name\n");
    printf("3. List all names\n");
    printf("4. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        cyberpunkInterface();
        scanf("%d", &choice);
        getchar(); // to consume newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter the name to insert: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                root = insert(root, name);
                printf("Name '%s' added to the database.\n", name);
                break;
            case 2:
                printf("Enter the name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                if (search(root, name)) {
                    printf("Name '%s' found in the database!\n", name);
                } else {
                    printf("Name '%s' not found.\n", name);
                }
                break;
            case 3:
                printf("Listing all names in the database...\n");
                inOrderTraversal(root);
                break;
            case 4:
                deleteTree(root);
                printf("Exiting the Neon Net...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}