//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Exciting Node Structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key in the BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to do in-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to search a key in a BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value in the BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Key not found!\n");
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        printf("Deleting %d\n", root->key);
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
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Interactive Menu
void menu() {
    printf("\nWelcome to the Exciting Binary Search Tree Program!\n");
    printf("1. Insert a Node\n");
    printf("2. Search a Node\n");
    printf("3. Delete a Node\n");
    printf("4. In-Order Traversal\n");
    printf("5. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Successfully inserted %d!\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Found %d in the BST!\n", value);
                } else {
                    printf("%d not found!\n", value);
                }
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Operation completed for %d!\n", value);
                break;

            case 4:
                printf("In-Order Traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting the program. Have a great day!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}