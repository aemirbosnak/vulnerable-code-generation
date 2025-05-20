//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
struct Node* minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void freeTree(struct Node* root);

// Main function
int main() {
    struct Node* root = NULL; // Initializing the root
    int choice, value;

    printf("Welcome to the Binary Search Tree Program!\n");
    printf("Choose an option:\n");
    printf("1. Insert value\n");
    printf("2. Search for a value\n");
    printf("3. Delete a value\n");
    printf("4. Inorder traversal\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted!\n", value);
                break;

            case 2:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL)
                    printf("Value %d found in the tree!\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted (if it existed)!\n", value);
                break;

            case 4:
                printf("Inorder traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                freeTree(root);
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new value into the BST
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

// Search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Find the node with the minimum value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a specified value from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Tree is empty, nothing to delete.\n");
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Free all nodes in the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}