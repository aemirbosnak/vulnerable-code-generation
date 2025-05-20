//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
/*
 * Binary Search Tree
 *
 * A beginner-friendly example of a Binary Search Tree (BST) in C
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert(int key) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        struct node *current = root;
        struct node *parent;
        while (1) {
            parent = current;
            if (key < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    break;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    break;
                }
            }
        }
    }
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    root = NULL;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(25);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}