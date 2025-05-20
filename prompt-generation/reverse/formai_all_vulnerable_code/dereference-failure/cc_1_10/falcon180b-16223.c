//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Node structure for binary search tree
typedef struct node {
    char data[MAX_LEN];
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with given data
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the tree
void insert(Node** root, char* data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (strcmp((*root)->data, data) > 0) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Function to search for data in the tree
Node* search(Node* root, char* data) {
    if (root == NULL || strcmp(root->data, data) == 0) {
        return root;
    } else if (strcmp(root->data, data) > 0) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the tree in order traversal
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%s ", root->data);
    printTree(root->right);
}

// Main function to test the tree operations
int main() {
    Node* root = NULL;
    char* words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int numWords = sizeof(words)/sizeof(words[0]);

    for (int i = 0; i < numWords; i++) {
        insert(&root, words[i]);
    }

    printf("In-order traversal of the tree:\n");
    printTree(root);

    Node* searchResult = search(root, "kiwi");
    if (searchResult!= NULL) {
        printf("\nFound '%s' in the tree.\n", searchResult->data);
    } else {
        printf("\n'%s' not found in the tree.\n", "kiwi");
    }

    return 0;
}