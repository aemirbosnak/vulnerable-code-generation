//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, char* data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (strcmp(root->data, data) > 0) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node* root, char* data) {
    if (root == NULL || strcmp(root->data, data) == 0) {
        return root;
    } else if (strcmp(root->data, data) > 0) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void printInOrder(Node* root) {
    if (root!= NULL) {
        printInOrder(root->left);
        printf("%s ", root->data);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    char data[MAX_SIZE];

    printf("Enter the data to be inserted in the binary search tree: ");
    scanf("%s", data);

    root = insertNode(root, data);

    printf("Enter the data to be searched in the binary search tree: ");
    scanf("%s", data);

    Node* searchResult = searchNode(root, data);

    if (searchResult!= NULL) {
        printf("The data '%s' is present in the binary search tree.\n", data);
    } else {
        printf("The data '%s' is not present in the binary search tree.\n", data);
    }

    printf("In-order traversal of the binary search tree:\n");
    printInOrder(root);

    return 0;
}