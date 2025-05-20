//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode* insert(struct TreeNode *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to search for a value in the BST
struct TreeNode* search(struct TreeNode *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } 
    return search(root->right, data);
}

// Helper function for in-order traversal
void inOrder(struct TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Helper function for pre-order traversal
void preOrder(struct TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Helper function for post-order traversal
void postOrder(struct TreeNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the BST nodes
void freeTree(struct TreeNode *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode *root = NULL;
    int choice, num;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert a Number\n");
        printf("2. Search a Number\n");
        printf("3. In-Order Traversal\n");
        printf("4. Pre-Order Traversal\n");
        printf("5. Post-Order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                root = insert(root, num);
                printf("Inserted %d into BST.\n", num);
                break;

            case 2:
                printf("Enter number to search: ");
                scanf("%d", &num);
                struct TreeNode *found = search(root, num);
                if (found) {
                    printf("%d found in the BST!\n", num);
                } else {
                    printf("%d not found in the BST.\n", num);
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
                printf("Exiting the program...\n");
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    printf("Program ended!\n");
    return 0;
}