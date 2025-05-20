//Falcon-180B DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* newNode(char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given data into the tree
void insert(Node** root, char data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    if (data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

// Function to print the tree in inorder traversal
void printInorder(Node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%c ", root->data);
    printInorder(root->right);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert some nodes
    insert(&root, 'A');
    insert(&root, 'B');
    insert(&root, 'C');
    insert(&root, 'D');
    insert(&root, 'E');
    insert(&root, 'F');

    // Print the tree in inorder traversal
    printf("Inorder traversal of the tree is:\n");
    printInorder(root);

    return 0;
}