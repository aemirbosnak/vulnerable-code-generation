//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct node {
    char data[MAX_STR_LEN];
    int count;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->data, str, MAX_STR_LEN);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* str) {
    if (root == NULL) {
        return createNode(str);
    }

    if (strcmp(root->data, str) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->data, str) < 0) {
        root->right = insert(root->right, str);
    } else {
        root->left = insert(root->left, str);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%s (%d)\n", root->data, root->count);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "orange");

    printInOrder(root);

    return 0;
}