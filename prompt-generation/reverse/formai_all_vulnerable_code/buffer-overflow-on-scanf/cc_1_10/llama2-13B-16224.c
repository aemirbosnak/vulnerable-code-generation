//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new node with the given data
struct BSTNode *newNode(int data) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new element into the tree
void insert(struct BSTNode **root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else {
        struct BSTNode *current = *root;
        while (current != NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode(data);
                    break;
                } else {
                    insert( &current->left, data );
                }
            } else if (data > current->data) {
                if (current->right == NULL) {
                    current->right = newNode(data);
                    break;
                } else {
                    insert( &current->right, data );
                }
            } else {
                // Data already present in the tree, do nothing
            }
            current = current->left != NULL ? current->left : current->right;
        }
    }
}

// Function to search for an element in the tree
struct BSTNode *search(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

int main() {
    struct BSTNode *root = NULL;

    // Interactive menu for inserting and searching elements
    while (1) {
        printf("--- Binary Search Tree Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Exit\n");
        int choice = getchar();

        if (choice == '1') {
            int data;
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            insert(&root, data);
        } else if (choice == '2') {
            int data;
            printf("Enter the element to search: ");
            scanf("%d", &data);
            struct BSTNode *node = search(root, data);
            if (node != NULL) {
                printf("Found %d in the tree\n", node->data);
            } else {
                printf("Not found\n");
            }
        } else if (choice == '3') {
            break;
        }
    }

    return 0;
}