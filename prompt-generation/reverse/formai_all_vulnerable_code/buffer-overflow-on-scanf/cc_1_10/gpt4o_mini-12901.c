//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 10

// Structure for each node in the binary search tree.
typedef struct Node {
    char key[50];
    int value;
    struct Node *left, *right;
} Node;

// Function to create a new node.
Node* newNode(const char* key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the BST.
Node* insert(Node* root, const char* key, int value) {
    if (root == NULL) return newNode(key, value);
    
    if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key, value);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert(root->right, key, value);
    }
    
    return root;
}

// Function to search for a key in the BST.
Node* search(Node* root, const char* key) {
    if (root == NULL || strcmp(root->key, key) == 0) {
        return root;
    }
    
    if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Function to find the minimum key in the BST.
Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a key from the BST.
Node* deleteNode(Node* root, const char* key) {
    if (root == NULL) return root;

    if (strcmp(key, root->key) < 0) {
        root->left = deleteNode(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child.
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get the inorder successor (smallest in the right subtree).
        Node* temp = minValueNode(root->right);
        strcpy(root->key, temp->key);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->key);
    }
    
    return root;
}

// Function to do inorder traversal of the BST.
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s: %d\n", root->key, root->value);
        inorder(root->right);
    }
}

// Function to clear the entire BST.
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to demonstrate the futuristic binary search tree.
int main() {
    Node* root = NULL;

    // Futuristic interactive input for keys and values.
    char key[50];
    int value;
    printf("Welcome to the Futuristic Binary Search Tree Console\n");
    printf("--------------------------------------------------\n");
    
    while (1) {
        printf("Enter a command (insert/search/delete/inorder/exit): ");
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "insert") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, key, value);
            printf("Inserted %s: %d into BST\n", key, value);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter key to search: ");
            scanf("%s", key);
            Node* result = search(root, key);
            if (result != NULL) {
                printf("Found %s: %d\n", result->key, result->value);
            } else {
                printf("Key %s not found in BST.\n", key);
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter key to delete: ");
            scanf("%s", key);
            root = deleteNode(root, key);
            printf("Deleted key %s from BST\n", key);
        } else if (strcmp(command, "inorder") == 0) {
            printf("Inorder traversal of the BST:\n");
            inorder(root);
        } else {
            printf("Unknown command: %s. Please try again.\n", command);
        }
    }

    freeTree(root);
    printf("Exiting the Futuristic Binary Search Tree Console. Goodbye!\n");
    return 0;
}