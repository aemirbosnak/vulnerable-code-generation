//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: irregular
// Binary Search Tree Example Program

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void insert(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL) {
        root = node;
    } else {
        struct Node *curr = root;
        while (curr != NULL) {
            if (value < curr->value) {
                if (curr->left == NULL) {
                    curr->left = node;
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right == NULL) {
                    curr->right = node;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
}

void traverse(struct Node *node) {
    if (node == NULL) {
        return;
    }
    traverse(node->left);
    printf("%d ", node->value);
    traverse(node->right);
}

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int value;
        printf("Enter value: ");
        scanf("%d", &value);
        insert(value);
    }

    traverse(root);
    printf("\n");

    return 0;
}