//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to search for a value in the binary search tree
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search(root->left, value);
    }
    
    return search(root->right, value);
}

// Function to display the tree structure using ASCII art
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;  // Increase space between levels

    printTree(root->right, space); // Process right subtree first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value); // Print current node value

    printTree(root->left, space); // Process left subtree
}

// Function to traverse the tree in-order
void inOrder(TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

// Function to traverse the tree pre-order
void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to traverse the tree post-order
void postOrder(TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

// Main function demonstrating the operations on the BST
int main() {
    TreeNode* root = NULL;
    int choice, value;

    do {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Print Tree\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                TreeNode* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Binary Search Tree Structure:\n");
                printTree(root, 0);
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Free memory
    return 0;
}