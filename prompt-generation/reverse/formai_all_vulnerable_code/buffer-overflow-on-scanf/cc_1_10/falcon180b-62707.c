//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_TREE_HEIGHT 100

typedef struct treenode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct treenode *left;
    struct treenode *right;
} treenode;

void insert(treenode **root, char *word) {
    treenode *current = *root;
    int cmp;

    while (current!= NULL) {
        cmp = strcmp(current->word, word);
        if (cmp == 0) {
            current->count++;
            return;
        }
        else if (cmp < 0) {
            if (current->right == NULL) {
                current->right = (treenode *)malloc(sizeof(treenode));
                strcpy(current->right->word, word);
                current->right->count = 1;
                current->right->left = NULL;
                current->right->right = NULL;
            }
            else {
                current = current->right;
            }
        }
        else {
            if (current->left == NULL) {
                current->left = (treenode *)malloc(sizeof(treenode));
                strcpy(current->left->word, word);
                current->left->count = 1;
                current->left->left = NULL;
                current->left->right = NULL;
            }
            else {
                current = current->left;
            }
        }
    }
}

void printtree(treenode *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printtree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s (%d)\n", root->word, root->count);

    printtree(root->left, space);
}

int main() {
    treenode *root = NULL;

    char word[MAX_WORD_LENGTH];
    while (scanf("%s", word)!= EOF) {
        insert(&root, word);
    }

    printtree(root, 0);

    return 0;
}