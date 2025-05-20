//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node *root, int data);
void visualizeTree(Node *root, int space);
void freeTree(Node *root);

// Define the space increment for visualization
#define SPACE_INCREMENT 4

int main() {
    Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Visualization\n");
        printf("1. Insert a value\n");
        printf("2. Visualize tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Visualizing tree:\n");
                visualizeTree(root, 0);
                break;
            case 3:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new value into the BST
Node* insert(Node *root, int data) {
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

// Visualize the BST in a rotated manner
void visualizeTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
 
    space += SPACE_INCREMENT;

    visualizeTree(root->right, space);
    printf("\n");
    for (int i = SPACE_INCREMENT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    visualizeTree(root->left, space);
}

// Free the allocated memory for the tree
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}