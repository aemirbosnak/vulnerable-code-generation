//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
/*
 * Binary search tree example program
 *
 * In this program, we will demonstrate how to implement a binary search tree in C.
 * We will implement the following functions:
 *
 * 1. insert - insert a new node into the tree
 * 2. search - search for a node in the tree
 * 3. delete - delete a node from the tree
 * 4. print - print the tree in sorted order
 *
 * We will also demonstrate how to use the tree in a simple program that takes
 * input from the user and performs various operations on the tree.
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the tree
Node* search(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to delete a node from the tree
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        // If the node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // If the node has one child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children
        Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
        return root;
    } else if (data <= root->data) {
        root->left = delete(root->left, data);
    } else {
        root->right = delete(root->right, data);
    }
    return root;
}

// Function to print the tree in sorted order
void print_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    Node *root = NULL;
    int choice;
    int data;

    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Print\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                Node *node = search(root, data);
                if (node == NULL) {
                    printf("Data not found\n");
                } else {
                    printf("Data found\n");
                }
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 4:
                print_tree(root);
                printf("\n");
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}