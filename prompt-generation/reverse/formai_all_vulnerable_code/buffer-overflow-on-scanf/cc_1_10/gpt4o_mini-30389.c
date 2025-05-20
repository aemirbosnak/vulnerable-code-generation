//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

// Define a structure for the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value in the binary tree
Node* insert(Node* node, int data) {
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

// Function to perform inorder traversal of the tree
void inorderTraversal(Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Function to perform preorder traversal of the tree
void preorderTraversal(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function to perform postorder traversal of the tree
void postorderTraversal(Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

// Function to free the allocated memory
void freeTree(Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    Node* root = NULL;
    int input, choice;

    printf("Binary Tree Visualization Program\n");
    printf("1. Insert a number\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nChoose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &input);
                root = insert(root, input);
                printf("%d inserted successfully.\n", input);
                break;
            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Choose again.\n");
        }
    }

    return 0;
}