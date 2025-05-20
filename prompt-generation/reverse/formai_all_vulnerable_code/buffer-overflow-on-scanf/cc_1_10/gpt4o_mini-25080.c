//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent each node in the binary search tree
struct Node {
    char *name;         // Name of the survivor, representing the node value
    struct Node *left;  // Pointer to the left child
    struct Node *right; // Pointer to the right child
};

// Function to create a new node with survivor's name
struct Node* createNode(char *name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->name = malloc(strlen(name) + 1);
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform insertion in the binary search tree
struct Node* insert(struct Node* root, char *name) {
    if (root == NULL) {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name);
    } else {
        root->right = insert(root->right, name);
    }
    return root;
}

// Function to search for a survivor
struct Node* search(struct Node* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->name);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in the BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, char *name) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root->name);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root->name);
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        free(root->name);
        root->name = malloc(strlen(temp->name) + 1);
        strcpy(root->name, temp->name);
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

// Function to free all nodes in the BST
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->name);
        free(root);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    char command[50];
    char name[50];

    printf("=== Survivor Registry in a Post-Apocalyptic World ===\n");
    
    while (1) {
        printf("Commands: [add, search, delete, list, exit]: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter survivor's name: ");
            scanf("%s", name);
            root = insert(root, name);
            printf("Survivor %s added to the registry.\n", name);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter survivor's name to search: ");
            scanf("%s", name);
            struct Node* result = search(root, name);
            if (result) {
                printf("Survivor %s found!\n", name);
            } else {
                printf("Survivor %s not found.\n", name);
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter survivor's name to delete: ");
            scanf("%s", name);
            root = deleteNode(root, name);
            printf("Survivor %s deleted from the registry.\n", name);
        } else if (strcmp(command, "list") == 0) {
            printf("Listing all survivors:\n");
            inorderTraversal(root);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command, try again.\n");
        }
    }

    freeTree(root);
    printf("Registry cleared. Stay safe out there!\n");
    return 0;
}