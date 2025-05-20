//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: safe
/*
 * A unique C binary search tree example program in a safe style
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    Node *curr = *root;
    while (1) {
        if (data < curr->data) {
            if (curr->left == NULL) {
                curr->left = createNode(data);
                break;
            }
            curr = curr->left;
        } else if (data > curr->data) {
            if (curr->right == NULL) {
                curr->right = createNode(data);
                break;
            }
            curr = curr->right;
        } else {
            break;
        }
    }
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;
    int data = 0;
    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insert(&root, data);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}