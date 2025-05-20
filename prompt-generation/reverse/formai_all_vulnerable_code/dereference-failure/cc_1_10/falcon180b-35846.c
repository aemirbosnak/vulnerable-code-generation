//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, return a new node
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

// Function to print the BST in order traversal
void printInOrder(struct node* root) {
    if (root == NULL)
        return;

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the BST in post-order traversal
void printPostOrder(struct node* root) {
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct node* root = NULL;

    // Insert some values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the BST in order traversal
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Print the BST in pre-order traversal
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");

    // Print the BST in post-order traversal
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");

    return 0;
}