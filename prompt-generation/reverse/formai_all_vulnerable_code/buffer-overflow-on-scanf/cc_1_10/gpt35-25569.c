//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

typedef struct node {
    char* word;
    int count;
    struct node* left;
    struct node* right;
} Node;

void add_word(Node** root, char* word);
void print_freq(Node* root);
void free_tree(Node* root);

int main(void) {
    Node* root = NULL;
    char word[MAX_WORD_SIZE];

    printf("Enter text: ");
    while(scanf("%s", word) == 1) {
        add_word(&root, word);
    }

    print_freq(root);
    free_tree(root);

    return 0;
}

void add_word(Node** root, char* word) {
    if(*root == NULL) {
        *root = malloc(sizeof(Node));
        (*root)->word = strdup(word);
        (*root)->count = 1;
        (*root)->left = (*root)->right = NULL;
    }
    else {
        int cmp = strcmp(word, (*root)->word);
        if(cmp == 0) {
            (*root)->count++;
        }
        else if(cmp < 0) {
            add_word(&((*root)->left), word);
        }
        else {
            add_word(&((*root)->right), word);
        }
    }
}

void print_freq(Node* root) {
    if(root == NULL) {
        return;
    }

    print_freq(root->left);
    printf("%s : %d\n", root->word, root->count);
    print_freq(root->right);
}

void free_tree(Node* root) {
    if(root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->word);
    free(root);
}