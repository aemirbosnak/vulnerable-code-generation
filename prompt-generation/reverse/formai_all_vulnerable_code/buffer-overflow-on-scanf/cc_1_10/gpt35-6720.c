//FormAI DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node Definition
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a Node in BST
Node* insertNode(Node* pNode, int data) {
    if (pNode == NULL) {
        return createNode(data);
    }
    if (data < pNode->data) {
        pNode->left = insertNode(pNode->left, data);
    }
    else if (data > pNode->data) {
        pNode->right = insertNode(pNode->right, data);
    }
    return pNode;
}

// Function to Print BST Inorder Traversal
void inorderTraversal(Node* pNode) {
    if (pNode != NULL) {
        inorderTraversal(pNode->left);
        printf("%d ", pNode->data);
        inorderTraversal(pNode->right);
    }
}

// Driver function to run the program
int main() {
    Node* rootNode = NULL;  // Initialize Empty BST
    int numElements, element;
    printf("Enter number of elements to insert in BST: ");
    scanf("%d", &numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &element);
        rootNode = insertNode(rootNode, element);
    }
    printf("Inorder traversal of BST: ");
    inorderTraversal(rootNode);
    return 0;
}