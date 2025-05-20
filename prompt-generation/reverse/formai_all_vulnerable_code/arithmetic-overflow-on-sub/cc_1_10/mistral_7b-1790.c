//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ELEMENTS 20
#define MIN_VALUE -2147483647
#define MAX_VALUE 2147483647

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = newNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

bool searchNode(Node* root, int key) {
    if (root == NULL) {
        return false;
    } else if (key == root->key) {
        return true;
    } else if (key < root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

void inOrderTraversal(Node* root, void (*function)(int)) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, function);
    function(root->key);
    inOrderTraversal(root->right, function);
}

void printElement(int key) {
    printf("%d ", key);
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    int array[MAX_ELEMENTS];

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int randomKey = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        array[i] = randomKey;
        root = insertNode(root, randomKey);
    }

    printf("Created Binary Search Tree with %d elements:\n", MAX_ELEMENTS);

    printf("Elements in the tree:\n");
    inOrderTraversal(root, printElement);
    printf("\n");

    int keyToSearch;

    printf("Enter an integer to search for in the tree: ");
    scanf("%d", &keyToSearch);

    bool isPresent = searchNode(root, keyToSearch);

    if (isPresent) {
        printf("The integer %d is present in the tree.\n", keyToSearch);
    } else {
        printf("The integer %d is not present in the tree.\n", keyToSearch);
    }

    return 0;
}