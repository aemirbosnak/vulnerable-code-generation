//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

typedef struct node {
    char word[MAX_WORD_SIZE];
    int frequency;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(char *word) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, char *word) {
    if (root == NULL) {
        return createNode(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->frequency++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insertNode(root->right, word);
    } else {
        root->left = insertNode(root->left, word);
    }

    return root;
}

void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%s: %d\n", root->word, root->frequency);
    inorderTraversal(root->right);
}

int main() {
    FILE *fp;
    char word[MAX_WORD_SIZE];
    Node *root = NULL;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        root = insertNode(root, word);
    }

    fclose(fp);

    printf("Inorder traversal of binary search tree:\n");
    inorderTraversal(root);

    return 0;
}