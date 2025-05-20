//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
struct TreeNode* createNode(int data);
struct TreeNode* insertNode(struct TreeNode* root, int data);
struct TreeNode* searchNode(struct TreeNode* root, int data);
void inOrderTraversal(struct TreeNode* root);
void freeTree(struct TreeNode* root);

int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    printf("Welcome to the Binary Search Tree Program!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct TreeNode* result = searchNode(root, value);
                if (result != NULL) {
                    printf("Value %d found in the BST.\n", value);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("In-order Traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program. Freeing resources...\n");
                freeTree(root);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node into the BST
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Search for a value in the BST
struct TreeNode* searchNode(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Display the BST using in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Free the memory allocated for the BST
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}