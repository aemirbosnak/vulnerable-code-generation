//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void processFile(FILE *file, Word words[MAX_WORDS]) {
    char word[WORD_LENGTH];
    int currentWordIndex = 0;
    int inWord = 0;

    while (fscanf(file, " %s", word) != EOF) {
        for (int i = 0; i < currentWordIndex; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                inWord = 1;
                break;
            }
        }

        if (!inWord) {
            strcpy(words[currentWordIndex].word, word);
            words[currentWordIndex++].count = 1;
        }

        inWord = 0;
    }
}

void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Word words[MAX_WORDS];
    processFile(file, words);
    fclose(file);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "") != 0) {
            numWords++;
        }
    }

    printWords(words, numWords);

    return 0;
}