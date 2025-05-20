//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int count;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node* root, char* data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (strcmp(root->data, data) == 0) {
        root->count++;
        return;
    }

    if (strcmp(data, root->data) < 0) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

Node* search(Node* root, char* data) {
    if (root == NULL || strcmp(root->data, data)!= 0) {
        return NULL;
    }
    return root;
}

void deleteNode(Node* root, char* data) {
    if (root == NULL) {
        return;
    }

    if (strcmp(root->data, data) == 0) {
        if (root->count == 1) {
            free(root);
            root = NULL;
        } else {
            root->count--;
        }
        return;
    }

    if (strcmp(data, root->data) < 0) {
        deleteNode(root->left, data);
    } else {
        deleteNode(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%s (%d)\n", root->data, root->count);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    insert(root, "apple");
    insert(root, "banana");
    insert(root, "orange");
    insert(root, "grape");

    printf("In-order traversal:\n");
    inOrderTraversal(root);

    deleteNode(root, "orange");

    printf("\nIn-order traversal after deleting 'orange':\n");
    inOrderTraversal(root);

    return 0;
}