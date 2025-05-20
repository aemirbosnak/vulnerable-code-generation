//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
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

// Function to search for a value in the BST
int search(struct Node* root, int target) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        return 1;
    } 
    if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

// Function for in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the functionality of the BST
int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Binary Search Tree (BST) Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Inorder Traversal\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted into the BST.\n", data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("%d found in the BST.\n", data);
                } else {
                    printf("%d not found in the BST.\n", data);
                }
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}