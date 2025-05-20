//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data in the tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to traverse inorder
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n;

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    printf("Enter the nodes:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal of the binary search tree:\n");
    inorder(root);

    return 0;
}