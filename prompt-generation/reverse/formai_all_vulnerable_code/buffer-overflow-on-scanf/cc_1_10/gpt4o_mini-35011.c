//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Struct for the binary search tree node
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
TreeNode* insert(TreeNode* root, int data) {
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

// Function to do in-order traversal of the BST and visualize it
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Function to visualize the tree structure
void visualizeTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 10; // Increase distance between levels

    visualizeTree(root->right, space); // Right child first

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    visualizeTree(root->left, space); // Left child
}

// Function to free the memory used by the tree
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = NULL;
    int choice, data;

    do {
        printf("1. Insert an element into the BST\n");
        printf("2. Visualize the BST\n");
        printf("3. Print in-order traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the BST\n", data);
                break;

            case 2:
                printf("Visualizing the binary search tree:\n");
                visualizeTree(root, 0);
                break;

            case 3:
                printf("In-order traversal of the BST: ");
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    freeTree(root); // Free memory allocated for the tree
    return 0;
}