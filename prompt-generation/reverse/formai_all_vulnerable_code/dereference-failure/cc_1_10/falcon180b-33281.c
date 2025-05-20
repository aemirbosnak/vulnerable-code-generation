//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int numWords;
} WordList;

void initializeWordList(WordList *wordList) {
    wordList->words = NULL;
    wordList->numWords = 0;
}

void addWord(WordList *wordList, char *word) {
    WordFrequency *newWords = realloc(wordList->words, sizeof(WordFrequency) * (wordList->numWords + 1));

    if (newWords == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }

    wordList->words = newWords;

    strcpy(wordList->words[wordList->numWords].word, word);
    wordList->words[wordList->numWords].frequency = 1;
    wordList->numWords++;
}

void printWordList(WordList *wordList) {
    for (int i = 0; i < wordList->numWords; i++) {
        printf("%s: %d\n", wordList->words[i].word, wordList->words[i].frequency);
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }

    WordList wordList;
    initializeWordList(&wordList);

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(&wordList, word);
    }

    fclose(file);

    printWordList(&wordList);

    return 0;
}