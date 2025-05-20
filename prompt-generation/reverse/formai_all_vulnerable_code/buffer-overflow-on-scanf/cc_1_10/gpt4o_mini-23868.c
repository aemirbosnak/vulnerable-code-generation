//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BST {
    Node *root;
} BST;

// Function Prototypes
BST* createBST();
Node* createNode(int data);
void insert(BST *tree, int data);
void inorderTraversal(Node *node);
Node* search(Node *node, int data);
void freeTree(Node *node);

// Futuristic Interface for User Interaction
void displayMenu();
int getInput();

int main() {
    BST *myTree = createBST();
    int choice, data;

    do {
        displayMenu();
        choice = getInput();

        switch(choice) {
            case 1:
                printf("Enter the number to insert: ");
                data = getInput();
                insert(myTree, data);
                printf("%d has been inserted into the tree.\n", data);
                break;
            case 2:
                printf("Enter the number to search: ");
                data = getInput();
                Node *foundNode = search(myTree->root, data);
                if (foundNode) {
                    printf("Number %d found in the tree.\n", data);
                } else {
                    printf("Number %d not found in the tree.\n", data);
                }
                break;
            case 3:
                printf("Inorder Traversal of the Binary Search Tree:\n");
                inorderTraversal(myTree->root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program...\n");
                // Free the tree before exit
                freeTree(myTree->root);
                free(myTree);
                break;
            default:
                printf("Invalid choice! Please select from the menu.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to create a new Binary Search Tree
BST* createBST() {
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

// Function to create a new Node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the Binary Search Tree
void insert(BST *tree, int data) {
    Node *newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (1) {
        parent = current;
        if (data < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;
                return;
            }
        }
    }
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Function to search for a number in the tree
Node* search(Node *node, int data) {
    if (node == NULL || node->data == data)
        return node;
    
    if (data < node->data)
        return search(node->left, data);
    
    return search(node->right, data);
}

// Function to free the memory allocated for the tree
void freeTree(Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Galactic Binary Search Tree ---\n");
    printf("1. Insert a Number\n");
    printf("2. Search for a Number\n");
    printf("3. Display Inorder Traversal\n");
    printf("4. Exit\n");
    printf("Select your option: ");
}

// Function to get input from the user
int getInput() {
    int value;
    scanf("%d", &value);
    return value;
}