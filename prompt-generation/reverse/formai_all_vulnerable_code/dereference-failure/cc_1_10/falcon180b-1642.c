//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the binary search tree in order traversal
void inOrder(struct Node* root) {
    if (root!= NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function to test the binary search tree implementation
int main() {
    struct Node* root = NULL;
    
    // Insert values into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    
    // Print the binary search tree in order traversal
    printf("In-order traversal of the binary search tree:\n");
    inOrder(root);
    printf("\n");
    
    // Search for a value in the binary search tree
    struct Node* searchResult = search(root, 4);
    if (searchResult!= NULL) {
        printf("Value %d found in the binary search tree.\n", searchResult->data);
    } else {
        printf("Value %d not found in the binary search tree.\n", 4);
    }
    
    return 0;
}