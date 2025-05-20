//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new node with the given data into the tree rooted at root
void insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// Search for a node with the given data in the tree rooted at root
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Print the tree rooted at root in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Free the memory used by the tree rooted at root
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a new tree
    Node* root = NULL;

    // Insert some nodes
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Print the tree
    printf("Tree:\n");
    printTree(root);

    // Search for a node
    Node* searchNode = search(root, 7);
    if (searchNode!= NULL) {
        printf("Found node with data %d\n", searchNode->data);
    } else {
        printf("Node not found\n");
    }

    // Free the memory used by the tree
    freeTree(root);

    return 0;
}