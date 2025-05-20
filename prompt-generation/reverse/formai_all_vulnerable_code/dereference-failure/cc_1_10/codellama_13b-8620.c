//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: synchronous
/*
 * A unique C Binary search tree example program in a synchronous style
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        Node *current = *root;
        while (current != NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = createNode(data);
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = createNode(data);
                    break;
                }
                current = current->right;
            }
        }
    }
}

void traverseTree(Node *root) {
    if (root != NULL) {
        traverseTree(root->left);
        printf("%d ", root->data);
        traverseTree(root->right);
    }
}

int main() {
    Node *root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 15);
    insertNode(&root, 5);
    insertNode(&root, 7);
    insertNode(&root, 12);
    insertNode(&root, 17);
    insertNode(&root, 20);

    printf("Inorder traversal of the tree:\n");
    traverseTree(root);

    return 0;
}