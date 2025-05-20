//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a new node in the BST
Node* insert(Node* root, int id, const char* name) {
    if (root == NULL) {
        return createNode(id, name);
    }

    if (id < root->id) {
        root->left = insert(root->left, id, name);
    } else if (id > root->id) {
        root->right = insert(root->right, id, name);
    } else {
        printf("Duplicate ID %d not inserted.\n", id);
    }

    return root;
}

// Recursive function to search for a node with a specific ID
Node* search(Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return search(root->left, id);
    }

    return search(root->right, id);
}

// Recursive function to display nodes in order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("ID: %d, Name: %s\n", root->id, root->name);
        inOrder(root->right);
    }
}

// Function to free the allocated memory for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, id;
    char name[50];

    while (1) {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Insert record\n");
        printf("2. Search record by ID\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("\nChoose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                root = insert(root, id, name);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Node* result = search(root, id);
                if (result != NULL) {
                    printf("Found: ID: %d, Name: %s\n", result->id, result->name);
                } else {
                    printf("Record with ID %d not found.\n", id);
                }
                break;

            case 3:
                printf("\nAll records in order:\n");
                inOrder(root);
                break;

            case 4:
                freeTree(root);
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}