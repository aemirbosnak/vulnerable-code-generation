//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
Node* insertNode(Node* root, int data) {
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

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to visualize tree structure
void printTree(Node* root, int space, int level) {
    if (root == NULL) {
        return;
    }

    space += level;
    
    // Process right child first
    printTree(root->right, space, level);

    // Print current node after space
    printf("\n");
    for (int i = level; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space, level);
}

// Function to find the minimum value node
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Visualization\n");
        printf("1. Insert Value\n");
        printf("2. Delete Value\n");
        printf("3. In-Order Traversal\n");
        printf("4. Print Tree Structure\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Tree Structure:\n");
                printTree(root, 0, 5);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}