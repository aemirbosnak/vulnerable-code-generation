//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TREE_HEIGHT 100
#define MAX_WORD_LENGTH 100

typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *left;
    struct node *right;
} node_t;

void insert_word(node_t *root, char *word) {
    node_t *current = root;
    int level = 0;

    while (level < MAX_TREE_HEIGHT && current!= NULL) {
        if (strcmp(word, current->word) < 0) {
            if (current->left == NULL) {
                current->left = malloc(sizeof(node_t));
                strcpy(current->left->word, word);
                current->left->count = 1;
                current->left->left = NULL;
                current->left->right = NULL;
            } else {
                current = current->left;
            }
        } else if (strcmp(word, current->word) > 0) {
            if (current->right == NULL) {
                current->right = malloc(sizeof(node_t));
                strcpy(current->right->word, word);
                current->right->count = 1;
                current->right->left = NULL;
                current->right->right = NULL;
            } else {
                current = current->right;
            }
        } else {
            current->count++;
            return;
        }
        level++;
    }
}

void print_tree(node_t *root, int space) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, space + 4);
    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s (%d)\n", root->word, root->count);
    print_tree(root->left, space + 4);
}

int main() {
    node_t *root = malloc(sizeof(node_t));
    strcpy(root->word, "");
    root->count = 0;
    root->left = NULL;
    root->right = NULL;

    char word[MAX_WORD_LENGTH];

    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        word[strcspn(word, "\n")] = '\0';
        if (strlen(word) == 0) {
            continue;
        }
        insert_word(root, word);
    }

    print_tree(root, 0);

    return 0;
}