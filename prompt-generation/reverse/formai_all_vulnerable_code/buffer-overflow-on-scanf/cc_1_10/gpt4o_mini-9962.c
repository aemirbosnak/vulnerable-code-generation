//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
    if (value < root->data) {
        return search(root->left, value);
    }
    
    return search(root->right, value);
}

// In-order traversal of the BST
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to free the allocated memory of the tree
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Surprise! The main function that brings everything together
int main() {
    struct Node *root = NULL; // Start with an empty tree
    int choice, value;

    printf("Welcome to the Binary Search Tree surprise party!\n");
    
    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Insert a number\n");
        printf("2. Search for a number\n");
        printf("3. Display in-order\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Number %d inserted successfully!\n", value);
                break;
            case 2:
                printf("Enter a number to search: ");
                scanf("%d", &value);
                struct Node *foundNode = search(root, value);
                if (foundNode) {
                    printf("Surprise! The number %d is found in the tree!\n", value);
                } else {
                    printf("Oh no! The number %d is not in our vibrant tree.\n", value);
                }
                break;
            case 3:
                printf("Here’s our tree in-order (sorted): ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the surprise party... Thank you for joining!\n");
                freeTree(root);
                exit(0);
            default:
                printf("Oops! That’s not a valid option; try again.\n");
        }
    }

    return 0; // Surprise, we never reach here!
}