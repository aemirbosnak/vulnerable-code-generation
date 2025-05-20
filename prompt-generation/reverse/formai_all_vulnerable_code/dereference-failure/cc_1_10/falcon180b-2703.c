//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: retro
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
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert data into the BST
struct node* insert(struct node* root, int data) {
    // If the root is null, create a new node and return it
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // Return the unchanged node pointer
    return root;
}

// Function to search for a node with the given data in the BST
struct node* search(struct node* root, int data) {
    // If the root is null or the data is found, return the node pointer
    if (root == NULL || root->data == data)
        return root;

    // If the data is less than the root's data, move to the left child
    if (data < root->data)
        return search(root->left, data);

    // Otherwise, move to the right child
    return search(root->right, data);
}

// Function to print the BST in order traversal
void printOrder(struct node* root) {
    if (root!= NULL) {
        printOrder(root->left);
        printf("%d ", root->data);
        printOrder(root->right);
    }
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Function to print the BST in post-order traversal
void printPostOrder(struct node* root) {
    if (root!= NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}

// Driver program to test the above functions
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST is \n");
    printOrder(root);
    printf("\n");

    printf("Pre-order traversal of the BST is \n");
    printPreOrder(root);
    printf("\n");

    printf("Post-order traversal of the BST is \n");
    printPostOrder(root);
    printf("\n");

    printf("Searching for 40 \n");
    struct node* res = search(root, 40);
    if (res!= NULL)
        printf("Found\n");
    else
        printf("Not found\n");

    return 0;
}