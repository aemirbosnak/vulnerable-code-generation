//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: accurate
/*
 * Program to demonstrate the working of Binary Search Tree
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void insert(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        struct Node *temp = root;
        while (temp != NULL) {
            if (data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(5);
    insert(15);
    insert(25);

    inorder(root);

    return 0;
}