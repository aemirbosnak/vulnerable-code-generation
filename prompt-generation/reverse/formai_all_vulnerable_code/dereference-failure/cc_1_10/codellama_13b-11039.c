//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: future-proof
// BinarySearchTree.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Insert a new node into the tree
void insert(struct Node** root, int value) {
    if (*root == NULL) {
        *root = malloc(sizeof(struct Node));
        (*root)->data = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (value < (*root)->data) {
            insert(&(*root)->left, value);
        } else {
            insert(&(*root)->right, value);
        }
    }
}

// Search for a value in the tree
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    } else {
        if (value == root->data) {
            return 1;
        } else if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }
}

// Print the tree in-order
void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Print the tree pre-order
void printPreOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Print the tree post-order
void printPostOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");
    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");
    printf("Searching for value 6: %d\n", search(root, 6));
    return 0;
}