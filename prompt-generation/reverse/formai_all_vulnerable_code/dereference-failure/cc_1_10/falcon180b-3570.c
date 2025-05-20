//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the binary search tree
typedef struct Node {
    char data[50];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insert(Node* root, char* data) {
    // If the root is NULL, create a new node as the root
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    // Traverse the tree to find the correct position to insert the new node
    if (strcmp(data, root->data) < 0) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    // Return the modified root node
    return root;
}

// Function to print the data in the binary search tree in alphabetical order
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    printTree(root->left);

    // Print the data at the current node
    printf("%s ", root->data);

    // Traverse the right subtree
    printTree(root->right);
}

// Function to search for a node in the binary search tree
Node* search(Node* root, char* data) {
    // If the root is NULL, the node does not exist in the tree
    if (root == NULL) {
        return NULL;
    }

    // Traverse the tree to find the node with the given data
    if (strcmp(data, root->data) == 0) {
        return root;
    }
    else if (strcmp(data, root->data) < 0) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

int main() {
    Node* root = NULL;

    // Insert some nodes into the tree
    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "cherry");
    root = insert(root, "date");
    root = insert(root, "elderberry");

    // Print the data in the tree in alphabetical order
    printf("Data in the tree:\n");
    printTree(root);

    printf("\nSearching for 'cherry'...\n");
    Node* cherryNode = search(root, "cherry");
    if (cherryNode!= NULL) {
        printf("Found 'cherry'!\n");
    }
    else {
        printf("Did not find 'cherry'.\n");
    }

    printf("\nSearching for 'grape'...\n");
    Node* grapeNode = search(root, "grape");
    if (grapeNode!= NULL) {
        printf("Found 'grape'!\n");
    }
    else {
        printf("Did not find 'grape'.\n");
    }

    return 0;
}