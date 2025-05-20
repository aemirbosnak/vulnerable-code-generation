//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* name, int age) {
    if (root == NULL) {
        root = createNode(name, age);
    } else if (strcmp(root->name, name) < 0) {
        root->right = insert(root->right, name, age);
    } else {
        root->left = insert(root->left, name, age);
    }
    return root;
}

Node* search(Node* root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    } else if (strcmp(root->name, name) < 0) {
        return search(root->right, name);
    } else {
        return search(root->left, name);
    }
}

void printInOrder(Node* root) {
    if (root!= NULL) {
        printInOrder(root->left);
        printf("%s %d\n", root->name, root->age);
        printInOrder(root->right);
    }
}

void printPreOrder(Node* root) {
    if (root!= NULL) {
        printf("%s %d\n", root->name, root->age);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(Node* root) {
    if (root!= NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%s %d\n", root->name, root->age);
    }
}

int main() {
    Node* root = NULL;
    char name[MAX_NAME_LENGTH];
    int age;

    printf("Enter name and age (q to quit):\n");
    while (scanf("%s %d", name, &age) == 2) {
        root = insert(root, name, age);
    }

    printf("In-order traversal:\n");
    printInOrder(root);

    printf("\nPre-order traversal:\n");
    printPreOrder(root);

    printf("\nPost-order traversal:\n");
    printPostOrder(root);

    printf("\nSearch for %s: %s\n", "Alice", search(root, "Alice")? "Found" : "Not found");

    return 0;
}