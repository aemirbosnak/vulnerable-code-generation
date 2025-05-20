//FormAI DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
// Romeo and Juliet C Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

// Declaration of a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Function to traverse the BST in inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    printf("Enter the number of elements you want to insert in the BST, Juliet:\n");
    int n, data;
    Node* root = NULL;
    scanf("%d", &n);
    printf("Enter %d elements one by one, Romeo:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("The elements in the BST in inorder traversal are:\n");
    inorder(root);
    printf("\nEnter the element you want to search in the BST, Juliet:\n");
    int x;
    scanf("%d", &x);
    Node* found = search(root, x);
    if (found == NULL) {
        printf("Element not found, Romeo.\n");
    }
    else {
        printf("Element found, Romeo.\n");
    }
    return 0;
}