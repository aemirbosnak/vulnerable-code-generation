//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char word[MAX_SIZE];
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, char *word) {
    if (root == NULL) {
        return createNode(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert(root->right, word);
    } else {
        root->left = insert(root->left, word);
    }

    return root;
}

void inOrderTraversal(Node *root) {
    if (root!= NULL) {
        inOrderTraversal(root->left);
        printf("%s: %d\n", root->word, root->count);
        inOrderTraversal(root->right);
    }
}

void main() {
    FILE *file;
    char word[MAX_SIZE];
    Node *root = NULL;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        root = insert(root, word);
    }

    fclose(file);

    inOrderTraversal(root);
}