//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a new node in the binary tree
TreeNode* insert(TreeNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to calculate the height of the tree
int height(TreeNode* node) {
    if (node == NULL) {
        return -1; // Returns -1 for height of null node
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to visualize the binary tree
void printTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10; // Increase distance between levels

    printTree(root->right, space); // Process right child first

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" "); // Print spaces
    }
    printf("%d\n", root->data); // Print the node

    printTree(root->left, space); // Process left child
}

// Function to free the tree
void freeTree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    TreeNode* root = NULL;
    int data;

    printf("Enter numbers to insert into the binary tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = insert(root, data);
    }

    printf("\nHeight of the tree: %d\n", height(root));

    printf("\nBinary Tree Visualization:\n");
    printTree(root, 0);

    freeTree(root); // Clean up memory
    return 0;
}