//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct node {
    char word[WORD_LENGTH];
    int count;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertWord(Node* root, char* word) {
    if (root == NULL) {
        root = createNode(word);
        return;
    }
    if (strcmp(root->word, word) < 0) {
        insertWord(root->right, word);
    } else if (strcmp(root->word, word) > 0) {
        insertWord(root->left, word);
    } else {
        root->count++;
    }
}

void printWords(Node* root, FILE* fp) {
    if (root!= NULL) {
        if (root->left!= NULL) {
            printWords(root->left, fp);
        }
        fprintf(fp, "%s %d\n", root->word, root->count);
        if (root->right!= NULL) {
            printWords(root->right, fp);
        }
    }
}

int main() {
    FILE* fp = fopen("words.txt", "r");
    char word[WORD_LENGTH];
    Node* root = NULL;
    int totalWords = 0;
    int uniqueWords = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        totalWords++;
        insertWord(root, word);
    }
    fclose(fp);
    printWords(root, stdout);
    printf("Total words: %d\n", totalWords);
    printf("Unique words: %d\n", uniqueWords);
    return 0;
}