//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value in the binary tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function for in-order traversal
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
}

// Function to free the memory of the tree
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to read user input and insert it to the tree
void readInputAndInsert(struct Node** root) {
    int value;
    printf("Enter an integer value (negative value to stop): ");
    scanf("%d", &value);
    
    if (value < 0) {
        return;
    }
    
    *root = insert(*root, value);
    readInputAndInsert(root);
}

int main() {
    struct Node* root = NULL;

    readInputAndInsert(&root);

    printf("In-order traversal of the tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}