//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

// Node structure of the binary search tree
typedef struct node {
    int data;
    struct node *left, *right;
}BST_node;

// Funtion to create a new node
BST_node *createNode(int value) {
    BST_node *newNode = (BST_node*)malloc(sizeof(BST_node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode; 
}

// Function to insert a node in the binary search tree
BST_node *insertNode(BST_node *root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insertNode(root->left, value);
    else if(value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

// Function to traverse the binary search tree in Inorder fashion
void inOrderTraversal(BST_node *root) {
    if(root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to delete a node from binary search tree
BST_node *deleteNode(BST_node *root, int key) {
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            BST_node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            BST_node *temp = root->left;
            free(root);
            return temp;
        }
        BST_node *temp = root->right;
        while(temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

// Main function
int main() {
    BST_node *root = NULL;  // Initializing an empty binary tree
    int choice, value;
    while(1) {
        printf("\n\nBinary Search Tree Operations:\n");
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Inorder traversal");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the value of node to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("\nNode inserted successfully!");
                break;
            case 2:
                printf("\nEnter the value of node to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("\nNode deleted successfully!");
                break;
            case 3:
                printf("\nInorder traversal of the binary search tree: ");
                inOrderTraversal(root);
                break;
            case 4:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}