//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to print the tree in a visually appealing way
void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

// Main function to test the tree
int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    printf("Binary Search Tree:\n");
    printTree(root, 0);
    return 0;
}