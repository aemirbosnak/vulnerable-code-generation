//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: immersive
/*
 *  Binary Search Tree Example Program
 *  Immersive C Programming
 */

#include <stdio.h>
#include <stdlib.h>

// Define structure for tree nodes
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new tree node
node_t* new_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the tree
void insert_node(node_t **root, int data) {
    // If root is NULL, create a new node and return
    if (*root == NULL) {
        *root = new_node(data);
        return;
    }

    // If the data is less than the current node's data, insert on the left
    if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    }
    // If the data is greater than the current node's data, insert on the right
    else {
        insert_node(&(*root)->right, data);
    }
}

// Function to find a node in the tree
node_t* find_node(node_t *root, int data) {
    // If the root is NULL, the data is not in the tree
    if (root == NULL) {
        return NULL;
    }

    // If the data is less than the current node's data, search on the left
    if (data < root->data) {
        return find_node(root->left, data);
    }
    // If the data is greater than the current node's data, search on the right
    else if (data > root->data) {
        return find_node(root->right, data);
    }
    // If the data is equal to the current node's data, return the node
    else {
        return root;
    }
}

// Function to delete a node from the tree
void delete_node(node_t **root, int data) {
    // If the root is NULL, the data is not in the tree
    if (*root == NULL) {
        return;
    }

    // If the data is less than the current node's data, delete on the left
    if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
    }
    // If the data is greater than the current node's data, delete on the right
    else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
    }
    // If the data is equal to the current node's data, delete the node
    else {
        // If the current node has no children, just delete the node
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        // If the current node has only one child, delete the node and point the parent to the child
        else if ((*root)->left == NULL || (*root)->right == NULL) {
            node_t *child = (*root)->left == NULL ? (*root)->right : (*root)->left;
            free(*root);
            *root = child;
        }
        // If the current node has two children, find the in-order successor and delete that node
        else {
            node_t *successor = find_node((*root)->right, (*root)->data);
            (*root)->data = successor->data;
            delete_node(&(*root)->right, successor->data);
        }
    }
}

// Function to traverse the tree in-order
void in_order(node_t *root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int main() {
    node_t *root = NULL;
    int data, choice;

    // Insert nodes into the tree
    while (1) {
        printf("Enter a number to insert into the tree: ");
        scanf("%d", &data);
        insert_node(&root, data);
        printf("Tree after insertion: \n");
        in_order(root);
        printf("\n");
    }

    // Find a node in the tree
    printf("Enter a number to find in the tree: ");
    scanf("%d", &data);
    node_t *node = find_node(root, data);
    if (node == NULL) {
        printf("The number %d is not in the tree.\n", data);
    }
    else {
        printf("The number %d is in the tree.\n", data);
    }

    // Delete a node from the tree
    printf("Enter a number to delete from the tree: ");
    scanf("%d", &data);
    delete_node(&root, data);
    printf("Tree after deletion: \n");
    in_order(root);
    printf("\n");

    return 0;
}