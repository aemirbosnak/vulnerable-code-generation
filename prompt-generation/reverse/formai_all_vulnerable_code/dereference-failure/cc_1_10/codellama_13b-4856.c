//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
/*
 * Sherlock Holmes Binary Search Tree
 *
 * A unique C program that demonstrates a Binary Search Tree
 * using a Sherlock Holmes style.
 */

#include <stdio.h>
#include <stdlib.h>

// Struct for a node in the tree
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert(struct Node** root, int value) {
    // If the tree is empty, create a new node
    if (*root == NULL) {
        *root = newNode(value);
        return;
    }

    // If the value is less than the root, insert on the left
    if (value < (*root)->value) {
        insert(&(*root)->left, value);
    }

    // If the value is greater than the root, insert on the right
    if (value > (*root)->value) {
        insert(&(*root)->right, value);
    }
}

// Function to search for a value in the tree
int search(struct Node* root, int value) {
    // If the tree is empty, return -1
    if (root == NULL) {
        return -1;
    }

    // If the value is found, return the value
    if (root->value == value) {
        return value;
    }

    // If the value is less than the root, search the left subtree
    if (value < root->value) {
        return search(root->left, value);
    }

    // If the value is greater than the root, search the right subtree
    if (value > root->value) {
        return search(root->right, value);
    }

    // If the value is not found, return -1
    return -1;
}

// Function to delete a node from the tree
void deleteNode(struct Node** root, int value) {
    // If the tree is empty, do nothing
    if (*root == NULL) {
        return;
    }

    // If the value is found, delete the node
    if ((*root)->value == value) {
        struct Node* temp = *root;
        *root = NULL;
        free(temp);
        return;
    }

    // If the value is less than the root, delete from the left subtree
    if (value < (*root)->value) {
        deleteNode(&(*root)->left, value);
    }

    // If the value is greater than the root, delete from the right subtree
    if (value > (*root)->value) {
        deleteNode(&(*root)->right, value);
    }
}

// Function to print the tree
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->value);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert some values into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    // Search for a value in the tree
    int value = 7;
    printf("Searching for %d: ", value);
    if (search(root, value) != -1) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    // Delete a node from the tree
    value = 4;
    printf("Deleting %d: ", value);
    deleteNode(&root, value);
    printTree(root);
    printf("\n");

    // Print the tree
    printTree(root);

    return 0;
}