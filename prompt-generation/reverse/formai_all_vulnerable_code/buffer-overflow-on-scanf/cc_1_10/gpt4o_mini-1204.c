//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new binary tree node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node with given data
Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to visualize the binary tree
void printTreeUtil(Node* root, int space) {
    int COUNT = 10;
    if (root == NULL) return;

    space += COUNT;
    printTreeUtil(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) 
        printf(" ");
    printf("%d\n", root->data);
    
    printTreeUtil(root->left, space);
}

// Function to display the tree
void printTree(Node* root) {
    printTreeUtil(root, 0);
}

// Function to free up memory used by the tree
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to run the program
int main() {
    Node* root = NULL;

    printf("Welcome to the Binary Tree Visualization!\n");
    printf("Please enter integers to insert into the binary tree (type -1 to stop):\n");

    int value;
    while (1) {
        printf("Insert value: ");
        scanf("%d", &value);
        if (value == -1) break;
        root = insert(root, value);
    }

    printf("\nYour Binary Tree Visualization:\n");
    printTree(root);

    // Free the memory allocated for the tree
    freeTree(root);
    
    return 0;
}