//FormAI DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
// Romeo's Binary Search Tree
// Thine speaks of a tree, O Juliet, which doth aid in searching with glee.
// A Binary Search Tree, I bring to thee, its wonders to behold and see.

#include <stdio.h>
#include <stdlib.h>

// Structure of the tree nodes
struct node {
    int data;
    struct node *left, *right;
};

// Function to create new nodes
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert nodes into the tree
struct node *insertNode(struct node *root, int data) {
    if (root == NULL) 
        return createNode(data);
    else if (data < root->data) 
        root->left = insertNode(root->left, data);
    else if (data > root->data) 
        root->right = insertNode(root->right, data);
    return root;
}

// Function to search for a node in the tree
struct node *searchNode(struct node *root, int data) {
    if (root == NULL || root->data == data) 
        return root;
    else if (root->data < data) 
        return searchNode(root->right, data);
    else 
        return searchNode(root->left, data);
}

int main(void) {
    // An empty tree, with no branches to trace, was Romeo's starting place.
    struct node *root = NULL;
    int n = 0, data;
    
    // "But soft! What value through yonder prompt breaks? It is my numerical input!"
    printf("Enter how many values to insert into the tree: ");
    scanf("%d", &n);
    printf("Enter the values to insert into the tree:\n");
    
    // Romeo, with pen in hand, did welcome each new integer to his program's land.
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i+1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    
    // "O, speak again, bright angel! For in thee the search for a node doth hang."
    printf("\nEnter the value to search for in the tree: ");
    scanf("%d", &data);
    struct node *result = searchNode(root, data);
    
    if (result == NULL) 
        printf("Value not found in the tree.\n");
    else 
        printf("Value %d found in the tree!\n", result->data);
    
    return 0;
}