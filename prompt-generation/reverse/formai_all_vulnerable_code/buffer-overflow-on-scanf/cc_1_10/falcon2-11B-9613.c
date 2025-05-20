//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in BST
void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data < root->data) {
        if (root->left!= NULL) {
            insert(root->left, data);
        } else {
            root->left = createNode(data);
        }
    } else {
        if (root->right!= NULL) {
            insert(root->right, data);
        } else {
            root->right = createNode(data);
        }
    }
}

// Function to search a node in BST
int search(struct Node* root, int data) {
    if (root == NULL) {
        return -1;
    }

    if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print BST
void printBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printBST(root->left);
    printf("%d ", root->data);
    printBST(root->right);
}

int main() {
    int size, data;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    struct Node* root = NULL;
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        arr[i] = data;
        insert(root, data);
    }

    printf("\nCreated BST from array: ");
    printBST(root);

    printf("\nEnter the element to search: ");
    scanf("%d", &data);
    int result = search(root, data);

    if (result == 1) {
        printf("\nElement found in BST\n");
    } else {
        printf("\nElement not found in BST\n");
    }

    return 0;
}