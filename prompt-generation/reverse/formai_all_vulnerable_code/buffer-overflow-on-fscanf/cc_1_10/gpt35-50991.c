//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_WORDS 100000 // Maximum number of words to read
#define MAX_WORD_LENGTH 50 // Maximum length of a word

struct treeNode {
    char* word;
    int count;
    struct treeNode* left;
    struct treeNode* right;
};

void printTree(struct treeNode* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%s: %d\n", root->word, root->count);
        printTree(root->right);
    }
}

struct treeNode* addTreeWord(struct treeNode* root, char* word) {
    int cmp;
    if (root == NULL) {
        root = (struct treeNode*)malloc(sizeof(struct treeNode));
        root->word = strdup(word);
        root->count = 1;
        root->left = root->right = NULL;
    }
    else if ((cmp = strcmp(word, root->word)) == 0) {
        root->count++;
    }
    else if (cmp < 0) {
        root->left = addTreeWord(root->left, word);
    }
    else {
        root->right = addTreeWord(root->right, word);
    }
    return root;
}

void freeTree(struct treeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        free(root->word);
        freeTree(root->right);
        free(root);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    struct treeNode* root = NULL;

    while (fscanf(inputFile, "%s", word) != EOF) {
        char* end = &word[strlen(word)];
        while ((end > &word[0]) && !isalpha(*(end - 1))) {
            end--;
        }
        *end = '\0';
        if (strlen(word) == 0) {
            continue;
        }
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        root = addTreeWord(root, word);
    }

    printTree(root);
    freeTree(root);
    fclose(inputFile);

    return 0;
}