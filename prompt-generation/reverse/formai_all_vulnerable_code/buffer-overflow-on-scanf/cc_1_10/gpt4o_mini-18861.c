//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* node, int data);
struct Node* search(struct Node* root, int data);
void inOrderTraversal(struct Node* root);
void freeTree(struct Node* root);

// Create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new node into the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Search for a node with specific data in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// In-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Free the memory allocated for the tree
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Welcome to the Binary Search Tree (BST) Program!\n");
    printf("What would you like to do?\n");
    printf("1. Insert Data\n");
    printf("2. Search Data\n");
    printf("3. In-order Traversal\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the BST!\n", data);
                break;

            case 2:
                printf("Enter the integer to search: ");
                scanf("%d", &data);
                struct Node* foundNode = search(root, data);
                if (foundNode) {
                    printf("Found %d in the BST!\n", foundNode->data);
                } else {
                    printf("The value %d was not found in the BST.\n", data);
                }
                break;

            case 3:
                printf("In-order Traversal of BST yields: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting the program. Freeing allocated memory...\n");
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}