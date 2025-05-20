//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error!\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorderTraversal(Node *root, int *count) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, count);
    printf("%d ", root->key);
    (*count)++;
    inorderTraversal(root->right, count);
}

int main() {
    Node *root = NULL;
    int n, count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    inorderTraversal(root, &count);
    printf("\nNumber of elements: %d\n", count);

    return 0;
}