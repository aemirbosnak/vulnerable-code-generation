//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node in the BST
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
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
        root->key = temp->key; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
    }
    return root;
}

// Function to do inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to free memory allocated for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the operations on BST
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert a node
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d into the BST.\n", key);
                break;
            case 2: // Search for a node
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node* found = search(root, key);
                if (found != NULL) {
                    printf("Key %d found in the BST.\n", found->key);
                } else {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;
            case 3: // Delete a node
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted from the BST if it existed.\n", key);
                break;
            case 4: // Find minimum node
                {
                    Node* minNode = findMin(root);
                    if (minNode != NULL) {
                        printf("Minimum key in the BST: %d\n", minNode->key);
                    } else {
                        printf("BST is empty.\n");
                    }
                }
                break;
            case 5: // Find maximum node
                {
                    Node* maxNode = findMax(root);
                    if (maxNode != NULL) {
                        printf("Maximum key in the BST: %d\n", maxNode->key);
                    } else {
                        printf("BST is empty.\n");
                    }
                }
                break;
            case 6: // Inorder traversal
                printf("Inorder traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;
            case 7: // Exit
                freeTree(root);
                printf("Exiting the program. Memory freed.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}