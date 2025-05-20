//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26
#define ERROR 255
typedef struct TrieNode {
    int isEndOfWord;
    struct TrieNode *children[NUM_BUCKETS];
} TrieNode;
TrieNode *root = NULL;
void addWord(char *word) {
    TrieNode *currentNode = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = malloc(sizeof(TrieNode));
            currentNode->children[index]->isEndOfWord = 0;
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = 1;
}
int checkSpelling(char *word) {
    TrieNode *currentNode = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (currentNode->children[index] == NULL) {
            return ERROR;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->isEndOfWord;
}
int main() {
    root = malloc(sizeof(TrieNode));
    root->isEndOfWord = 0;
    int numWords;
    scanf("%d", &numWords);
    char word[MAX_WORD_LENGTH];
    for (int i = 0; i < numWords; i++) {
        scanf("%s", word);
        addWord(word);
    }
    char checkWord[MAX_WORD_LENGTH];
    int isValid;
    for (int i = 0; i < numWords; i++) {
        scanf("%s", checkWord);
        isValid = checkSpelling(checkWord);
        if (isValid == ERROR) {
            printf("Invalid word: %s\n", checkWord);
        }
    }
    return 0;
}