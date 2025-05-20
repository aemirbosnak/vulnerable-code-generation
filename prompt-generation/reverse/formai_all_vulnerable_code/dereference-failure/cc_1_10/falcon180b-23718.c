//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    int count;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node with the given data
Node* newNode(char data[MAX_SIZE]) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the tree
void insert(Node** root, char data[MAX_SIZE]) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    if (strcmp(data, (*root)->data) < 0)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

// Function to search for a node with the given data in the tree
Node* search(Node* root, char data[MAX_SIZE]) {
    if (root == NULL || strcmp(data, root->data)!= 0)
        return NULL;

    return root;
}

// Function to print the subtree rooted at the given node
void printSubtree(Node* root) {
    if (root == NULL)
        return;

    printf("%s (%d)\n", root->data, root->count);
    printSubtree(root->left);
    printSubtree(root->right);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert nodes into the tree
    insert(&root, "apple");
    insert(&root, "banana");
    insert(&root, "cherry");
    insert(&root, "date");
    insert(&root, "elderberry");

    // Search for a node in the tree
    Node* result = search(root, "banana");

    if (result!= NULL) {
        printf("Found node: %s\n", result->data);
        printSubtree(result);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}