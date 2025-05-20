//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert function to insert a new value in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search function to find a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to perform in-order traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal of the BST
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform post-order traversal of the BST
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to execute the BST operations
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. In-Order Traversal\n");
        printf("4. Pre-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("Value %d found in the BST.\n", value);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-Order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-Order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}