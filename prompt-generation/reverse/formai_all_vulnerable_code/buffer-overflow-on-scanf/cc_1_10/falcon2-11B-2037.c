//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define EMPTY -1

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *insert(Node *root, int value) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->data = value;
        root->left = root->right = NULL;
        return root;
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *search(Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    else if (root->data < value) {
        return search(root->right, value);
    }
    else {
        return search(root->left, value);
    }
}

int main() {
    Node *root = NULL;
    int value;

    printf("Enter the size of the tree: ");
    scanf("%d", &value);

    for (int i = 0; i < value; i++) {
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);

        root = insert(root, data);
    }

    printf("Enter the node to search for: ");
    scanf("%d", &value);

    Node *found = search(root, value);

    if (found == NULL) {
        printf("Node not found in the tree.\n");
    }
    else {
        printf("Node found at index %d.\n", found->data);
    }

    return 0;
}