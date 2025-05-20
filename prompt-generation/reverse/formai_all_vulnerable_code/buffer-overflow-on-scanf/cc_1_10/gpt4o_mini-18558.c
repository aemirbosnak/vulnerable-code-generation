//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the binary search tree
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

// Function to insert a new value in the BST
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node; // return the unchanged node pointer
}

// Function to perform in-order traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* node) {
    if (node == NULL) return;

    // Recursively free the left and right subtrees
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main program to demonstrate BST functionality
int main() {
    struct Node* root = NULL; // Start with an empty tree
    int choice, value;

    // User interface
    printf("====================================\n");
    printf("    RETRO BINARY SEARCH TREE\n");
    printf("====================================\n");
    do {
        printf("1. Insert a value\n");
        printf("2. In-Order Traversal\n");
        printf("3. Search for a value\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;

            case 2:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = search(root, value);
                if (result != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 4:
                printf("Exiting program. Freeing resources...\n");
                freeTree(root);
                printf("Resources freed. Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}