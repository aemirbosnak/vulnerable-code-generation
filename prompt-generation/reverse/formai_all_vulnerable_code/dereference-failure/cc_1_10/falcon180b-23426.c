//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void addWord(WordFrequency *wordFrequencies, int numWords, char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(wordFrequencies[i].word, word) == 0) {
            wordFrequencies[i].frequency++;
            return;
        }
    }
    if (numWords == MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    wordFrequencies[numWords].word = strdup(word);
    wordFrequencies[numWords].frequency = 1;
    numWords++;
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char ch;
    char word[MAX_WORD_LENGTH];
    int inWord = false;
    int numWords = 0;
    WordFrequency *wordFrequencies = malloc(sizeof(WordFrequency) * MAX_WORDS);
    if (wordFrequencies == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    memset(wordFrequencies, 0, sizeof(WordFrequency) * MAX_WORDS);

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalnum(ch)) {
            inWord = true;
        } else if (inWord) {
            word[strlen(word) - 1] = '\0';
            addWord(wordFrequencies, numWords, word);
            inWord = false;
        }
    }

    if (inWord) {
        word[strlen(word) - 1] = '\0';
        addWord(wordFrequencies, numWords, word);
    }

    fclose(file);

    printWordFrequencies(wordFrequencies, numWords);

    free(wordFrequencies);

    return 0;
}