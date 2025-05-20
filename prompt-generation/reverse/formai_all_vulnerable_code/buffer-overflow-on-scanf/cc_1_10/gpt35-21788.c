//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a Node of Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new Node and return its address
struct Node* create(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert data in the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        root = create(data);
        return root;
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search an element in the Binary Search Tree
struct Node* search(struct Node* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    else if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// Traverse all nodes of the Binary Search Tree in Inorder fashion
void inorder(struct Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function to test the Binary Search Tree
int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 12);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    insert(root, 15);
    printf("Inorder traversal of the Binary Search Tree:\n");
    inorder(root);
    printf("\n");
    int searchData;
    printf("Enter an element to search in the Binary Search Tree: ");
    scanf("%d", &searchData);
    struct Node* searchResult = search(root, searchData);
    if(searchResult == NULL) {
        printf("%d is not present in the Binary Search Tree\n", searchData);
    }
    else {
        printf("%d is present in the Binary Search Tree\n", searchData);
    }
    return 0;
}