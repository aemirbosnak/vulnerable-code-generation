//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: complete
// Binary Search Tree Program

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insert(struct Node** root, int data) {
    // If the root is NULL, create a new node and make it the root
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    // If the data is less than the root's data, recur for the left subtree
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }

    // If the data is greater than the root's data, recur for the right subtree
    else {
        insert(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int data) {
    // If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is found, return the root
    if (root->data == data) {
        return root;
    }

    // If the data is less than the root's data, recur for the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }

    // If the data is greater than the root's data, recur for the right subtree
    else {
        return search(root->right, data);
    }
}

// Function to delete a node from the binary search tree
void delete(struct Node** root, int data) {
    // If the root is NULL, return
    if (*root == NULL) {
        return;
    }

    // If the data is found, remove the node and return
    if ((*root)->data == data) {
        struct Node* temp = *root;
        *root = NULL;
        free(temp);
        return;
    }

    // If the data is less than the root's data, recur for the left subtree
    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    }

    // If the data is greater than the root's data, recur for the right subtree
    else {
        delete(&(*root)->right, data);
    }
}

// Function to print the binary search tree in sorted order
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Main function
int main() {
    // Create a new binary search tree
    struct Node* root = NULL;

    // Insert some nodes into the binary search tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);

    // Search for a node in the binary search tree
    struct Node* searchResult = search(root, 20);
    if (searchResult != NULL) {
        printf("Node found: %d\n", searchResult->data);
    }

    // Delete a node from the binary search tree
    delete(&root, 20);

    // Print the binary search tree in sorted order
    printTree(root);

    return 0;
}