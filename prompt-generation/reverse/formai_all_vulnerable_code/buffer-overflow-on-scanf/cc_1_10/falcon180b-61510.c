//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct node {
    char word[MAX_WORD_LEN];
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

void insert(Node* root, char* word) {
    if (root == NULL) {
        root = createNode(word);
    } else if (strcmp(root->word, word) < 0) {
        insert(root->right, word);
    } else if (strcmp(root->word, word) > 0) {
        insert(root->left, word);
    } else {
        root->count++;
    }
}

void printWords(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    printWords(root->right, space + 4);
    printf("%s%d %s\n", " ", root->count, root->word);
    printWords(root->left, space + 4);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    int numWords = 0;
    char input[MAX_WORD_LEN];
    while (scanf("%s", input)!= EOF) {
        strcpy(words[numWords], input);
        numWords++;
    }
    Node* root = NULL;
    for (int i = 0; i < numWords; i++) {
        insert(root, words[i]);
    }
    printf("Words in order of frequency:\n");
    printWords(root, 0);
    return 0;
}