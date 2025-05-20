//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Data structure for a Binary Search Tree node
struct node {
    int data;                       // Data to be stored in the node
    struct node* left;              // Pointer to the left subtree
    struct node* right;             // Pointer to the right subtree
};

// Helper function to create a new node with the given data
struct node* newNode(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Helper function to insert a node with the given data into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } 
    if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Helper function to find the minimum value in a subtree
int minValue(struct node* node) {
    int minVal = node->data;
    while (node->left != NULL) {
        minVal = node->left->data;
        node = node->left;
    }
    return minVal;
}

// Helper function to delete a node with the given key from the BST
struct node* delete(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = delete(root->left, key);
    } 
    else if (key > root->data) {
        root->right = delete(root->right, key);
    }
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        int temp = minValue(root->right);
        root->data = temp;
        // Delete the inorder successor
        root->right = delete(root->right, temp);
    }
    return root;
}

// Helper function to perform inorder traversal of the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver function to test the code
int main() {
    struct node* root = NULL;
    printf("Binary Search Tree Example Program in C\n");
    printf("======================================\n\n");
    printf("Enter the number of nodes to be inserted in the BST: ");
    int n;
    scanf("%d", &n);
    printf("Enter the values of the nodes: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n\nEnter the value of the node to be deleted: ");
    int key;
    scanf("%d", &key);
    root = delete(root, key);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);
    return 0;
}