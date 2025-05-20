//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct node* insert(struct node* root, int data) {
    if (!root)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a value in the binary search tree
struct node* search(struct node* root, int data) {
    if (!root || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Function to print the binary search tree in order traversal
void printOrder(struct node* root) {
    if (!root)
        return;

    printOrder(root->left);
    printf("%d ", root->data);
    printOrder(root->right);
}

// Function to print the binary search tree in pre-order traversal
void printPreOrder(struct node* root) {
    if (!root)
        return;

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the binary search tree in post-order traversal
void printPostOrder(struct node* root) {
    if (!root)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Driver code
int main() {
    struct node* root = NULL;

    // Insert values into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree in order traversal
    printf("Order traversal: ");
    printOrder(root);
    printf("\n");

    // Print the binary search tree in pre-order traversal
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the binary search tree in post-order traversal
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    return 0;
}