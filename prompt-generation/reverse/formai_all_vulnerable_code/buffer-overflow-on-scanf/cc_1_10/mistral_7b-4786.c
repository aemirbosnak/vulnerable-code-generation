//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 1; i < level; i++) {
        printf("  ");
    }

    printf("%s%d%s\n", (root->left == NULL ? "  |" : " / |"), root->data, (root->right == NULL ? "  \\" : " \\-"));

    if (root->left != NULL) {
        printTree(root->left, level + 1);
    }

    if (root->right != NULL) {
        printTree(root->right, level + 1);
    }
}

int main() {
    Node* root = NULL;

    printf("Artistic Tree Visualization\n");
    printf("----------------------------\n");
    printf("Enter integers to insert into the tree (0 to quit):\n");

    int data;
    while (scanf("%d", &data) == 1) {
        if (data == 0) {
            break;
        }

        insert(&root, data);
    }

    printf("\nTree visualization:\n");
    printTree(root, 0);

    return 0;
}