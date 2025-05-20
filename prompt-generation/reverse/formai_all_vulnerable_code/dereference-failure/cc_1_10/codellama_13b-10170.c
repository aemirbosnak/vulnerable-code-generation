//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insertNode(struct Node** root, int data) {
    // Create a new node with the given data
    struct Node* node = createNode(data);

    // If the tree is empty, make the new node the root
    if (*root == NULL) {
        *root = node;
        return;
    }

    // Otherwise, insert the node into the correct position in the tree
    struct Node* current = *root;
    while (current != NULL) {
        // If the data is less than the current node's data, go left
        if (data < current->data) {
            // If the left child is NULL, insert the node here
            if (current->left == NULL) {
                current->left = node;
                return;
            }
            // Otherwise, move left and check the left child
            else {
                current = current->left;
            }
        }
        // If the data is greater than the current node's data, go right
        else {
            // If the right child is NULL, insert the node here
            if (current->right == NULL) {
                current->right = node;
                return;
            }
            // Otherwise, move right and check the right child
            else {
                current = current->right;
            }
        }
    }
}

// Function to search for a node in the tree
bool searchNode(struct Node* root, int data) {
    // If the root is NULL, the data is not in the tree
    if (root == NULL) {
        return false;
    }

    // If the data is equal to the current node's data, return true
    if (root->data == data) {
        return true;
    }

    // Otherwise, search the left and right subtrees recursively
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Function to delete a node from the tree
void deleteNode(struct Node** root, int data) {
    // If the root is NULL, the data is not in the tree
    if (*root == NULL) {
        return;
    }

    // If the data is equal to the current node's data, delete the node
    if ((*root)->data == data) {
        struct Node* temp = *root;
        *root = NULL;
        free(temp);
        return;
    }

    // Otherwise, search the left and right subtrees recursively
    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
    }
    else {
        deleteNode(&(*root)->right, data);
    }
}

// Function to print the tree in a breadth-first manner
void printTree(struct Node* root) {
    // If the root is NULL, the tree is empty
    if (root == NULL) {
        return;
    }

    // Create a queue to hold the nodes to be visited
    struct Node* queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    // Loop until the queue is empty
    while (front != rear) {
        // Dequeue a node from the queue
        struct Node* node = queue[front++];

        // Print the node's data
        printf("%d ", node->data);

        // If the node has a left child, enqueue it
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        // If the node has a right child, enqueue it
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

int main() {
    // Create a new tree
    struct Node* root = NULL;

    // Insert some nodes into the tree
    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 2);
    insertNode(&root, 4);

    // Search for a node in the tree
    if (searchNode(root, 4)) {
        printf("The data 4 is in the tree.\n");
    }
    else {
        printf("The data 4 is not in the tree.\n");
    }

    // Delete a node from the tree
    deleteNode(&root, 4);

    // Print the tree
    printTree(root);

    return 0;
}