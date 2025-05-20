//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to print the tree in-order
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to display the tree structure
void printTree(Node* root, int space) {
    if (root == NULL) return;

    space += 5; // Increase distance between levels

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}

int main() {
    Node* root = NULL;
    int choice, value;

    printf("Binary Search Tree Visualization\n");
    printf("1. Insert Value\n");
    printf("2. Inorder Traversal\n");
    printf("3. Visualize Tree Structure\n");
    printf("0. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Tree Structure:\n");
                printTree(root, 0);
                break;
            case 0:
                printf("Exiting...\n");
                free(root);  // Not a proper free, but for demo purposes
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}