//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Creating new node
struct Node* getNewNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//Inserting values in the tree
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Searching for the value in the tree
struct Node* search(struct Node* root, int data) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->data == data) {
        return root;
    }
    else if(data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 8);
  
    int num;
    printf("Enter a number to be searched in the tree: ");
    scanf("%d", &num);
    struct Node* find = search(root, num);
    if(find == NULL) {
        printf("Value not found!\n");
    }
    else {
        printf("Value found in the tree!\n");
    }
    return 0;
}