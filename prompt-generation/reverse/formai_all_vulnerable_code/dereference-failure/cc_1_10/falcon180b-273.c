//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data in BST
struct Node* insert(struct Node* root, int data) {
    // If the root is null, create a new node
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged node pointer
    return root;
}

// Function to traverse the BST in In-order
void inOrder(struct Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;

    // Insert 50
    root = insert(root, 50);

    // Insert 30
    root = insert(root, 30);

    // Insert 20
    root = insert(root, 20);

    // Insert 40
    root = insert(root, 40);

    // Insert 70
    root = insert(root, 70);

    // Insert 60
    root = insert(root, 60);

    // Insert 80
    root = insert(root, 80);

    printf("In-order traversal of the BST is \n");
    inOrder(root);

    return 0;
}