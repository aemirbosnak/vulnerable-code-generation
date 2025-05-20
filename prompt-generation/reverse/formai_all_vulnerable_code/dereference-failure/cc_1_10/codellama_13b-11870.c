//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: energetic
/*
 * Binary Search Tree Example Program
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else {
        if (data < (*root)->data) {
            insert(&(*root)->left, data);
        } else {
            insert(&(*root)->right, data);
        }
    }
}

// Function to search a node in the binary search tree
int search(struct Node* root, int data) {
    if (root == NULL) {
        return -1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root->data;
    }
}

// Function to delete a node from the binary search tree
void delete(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    } else if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            struct Node* temp = (*root)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            (*root)->data = temp->data;
            delete(&(*root)->left, temp->data);
        }
    }
}

// Function to print the binary search tree
void print(struct Node* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

// Driver code
int main() {
    struct Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    print(root);
    printf("\n");
    delete(&root, 30);
    print(root);
    return 0;
}