//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes.
struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
void inorderTraversal(struct Node* root);
struct Node* searchNode(struct Node* root, int data);
struct Node* findMin(struct Node* root);
struct Node* deleteNode(struct Node* root, int data);
void freeTree(struct Node* root);

// Entry point of the program: a surreal experience in a binary search tree.
int main() {
    struct Node* root = NULL;
    int choice, value;

    // Welcome to the realm of binary search trees!
    printf("Welcome to the Binary Search Tree Adventure!\n\n");

    while (1) {
        // Display the menu options.
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Search Node\n");
        printf("4. Delete Node\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        // Choose the path through the forest of trees.
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Inserted %d into the tree.\n\n", value);
                break;

            case 2:
                printf("Inorder Traversal of the Tree: ");
                inorderTraversal(root);
                printf("\n\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = searchNode(root, value);
                if (foundNode) {
                    printf("Node with value %d found!\n\n", foundNode->data);
                } else {
                    printf("Node with value %d not found.\n\n", value);
                }
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deleted node with value %d (if it existed).\n\n", value);
                break;

            case 5:
                printf("Exiting the Binary Search Tree Adventure. Farewell!\n");
                freeTree(root);
                exit(0);

            default:
                printf("Invalid option! Choose wisely.\n\n");
                break;
        }
    }

    return 0;
}

// Function implementations for each mystical operation on the binary search tree.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree).
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node.
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor.
    }
    return root;
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}