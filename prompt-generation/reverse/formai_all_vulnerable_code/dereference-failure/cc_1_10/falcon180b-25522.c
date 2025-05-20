//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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

// Function to insert a value into the tree
void insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Function to search for a value in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the tree in order
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to print the tree pre-order
void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the tree post-order
void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;

    // Insert values into the tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);

    // Print the tree in order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Print the tree pre-order
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the tree post-order
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    // Search for a value in the tree
    Node* foundNode = search(root, 7);
    if (foundNode == NULL) {
        printf("Value not found.\n");
    } else {
        printf("Value found.\n");
    }

    return 0;
}