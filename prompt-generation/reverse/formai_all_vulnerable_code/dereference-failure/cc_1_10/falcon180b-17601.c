//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct tnode {
    char word[MAX_WORD_LEN];
    int count;
    struct tnode *left;
    struct tnode *right;
} TNode;

TNode *createNode(char *word) {
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TNode *insert(TNode *root, char *word) {
    if (root == NULL) {
        return createNode(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) > 0) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }

    return root;
}

void inorderTraversal(TNode *root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%s %d\n", root->word, root->count);
    inorderTraversal(root->right);
}

void main() {
    TNode *root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "cherry");
    root = insert(root, "date");
    root = insert(root, "elderberry");
    root = insert(root, "fig");
    root = insert(root, "grape");
    root = insert(root, "honeydew");

    printf("Inorder traversal:\n");
    inorderTraversal(root);
}