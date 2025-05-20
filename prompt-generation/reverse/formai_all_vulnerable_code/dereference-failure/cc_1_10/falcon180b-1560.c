//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: surrealist
// Binary Search Tree example program in a surrealist style

#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        root = newNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
struct node* search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to print the BST in surrealist style
void printSurreal(struct node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }
    printf("A %d-colored bird perches on a branch,\n", root->data);
    printSurreal(root->left);
    printf("its feathers shimmering like dreams.\n");
    printSurreal(root->right);
}

// Main function to test the BST operations
int main() {
    struct node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 12);

    printf("Searching for 5...\n");
    struct node* foundNode = search(root, 5);
    if (foundNode!= NULL) {
        printf("Found %d!\n", foundNode->data);
    } else {
        printf("Couldn't find %d.\n", 5);
    }

    printf("\nPrinting the tree in surrealist style...\n");
    printSurreal(root);

    return 0;
}