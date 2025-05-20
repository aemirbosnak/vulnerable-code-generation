//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* search(Node* root, int data);
Node* delete(Node* root, int data);
Node* findMin(Node* root);
void inorderTraversal(Node* root);
void freeTree(Node* root);

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is already present, do nothing
    return root;
}

// Function to search for a node in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
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
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal of BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory occupied by the tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "Invalid input. Please enter an integer.\n");
                    break;
                }
                root = insert(root, data);
                printf("%d inserted.\n", data);
                break;
            case 2:
                printf("Enter data to search: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "Invalid input. Please enter an integer.\n");
                    break;
                }
                Node* foundNode = search(root, data);
                if (foundNode) {
                    printf("%d found in the tree.\n", data);
                } else {
                    printf("%d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "Invalid input. Please enter an integer.\n");
                    break;
                }
                root = delete(root, data);
                printf("%d deleted from the tree.\n", data);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}