//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
// Example of a binary search tree in C

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary search tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertNode(struct TreeNode* root, int data) {
    // If the tree is empty, create a new node and insert it as the root
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    // If the data is less than the root node, insert it in the left subtree
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = createNode(data);
        } else {
            insertNode(root->left, data);
        }
    }

    // If the data is greater than the root node, insert it in the right subtree
    if (data > root->data) {
        if (root->right == NULL) {
            root->right = createNode(data);
        } else {
            insertNode(root->right, data);
        }
    }
}

// Function to search for a node in the binary search tree
struct TreeNode* searchNode(struct TreeNode* root, int data) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the data is less than the root node, search in the left subtree
    if (data < root->data) {
        return searchNode(root->left, data);
    }

    // If the data is greater than the root node, search in the right subtree
    if (data > root->data) {
        return searchNode(root->right, data);
    }

    // If the data is found, return the node
    if (data == root->data) {
        return root;
    }

    // If the data is not found, return NULL
    return NULL;
}

// Function to delete a node from the binary search tree
void deleteNode(struct TreeNode* root, int data) {
    // If the tree is empty, do nothing
    if (root == NULL) {
        return;
    }

    // If the data is less than the root node, delete in the left subtree
    if (data < root->data) {
        deleteNode(root->left, data);
    }

    // If the data is greater than the root node, delete in the right subtree
    if (data > root->data) {
        deleteNode(root->right, data);
    }

    // If the data is found, delete the node
    if (data == root->data) {
        free(root);
    }
}

// Function to traverse the binary search tree
void traverseTree(struct TreeNode* root) {
    // If the tree is empty, do nothing
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    traverseTree(root->left);

    // Print the data of the current node
    printf("%d ", root->data);

    // Traverse the right subtree
    traverseTree(root->right);
}

// Function to print the binary search tree
void printTree(struct TreeNode* root) {
    // Traverse the tree and print the data of each node
    traverseTree(root);
    printf("\n");
}

int main() {
    // Create a new binary search tree
    struct TreeNode* root = createNode(5);

    // Insert some nodes into the tree
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 7);

    // Search for a node in the tree
    struct TreeNode* node = searchNode(root, 3);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the tree
    deleteNode(root, 3);

    // Print the tree
    printTree(root);

    // Free the memory used by the tree
    free(root);

    return 0;
}