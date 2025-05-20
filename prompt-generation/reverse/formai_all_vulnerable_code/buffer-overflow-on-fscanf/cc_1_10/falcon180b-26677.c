//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b) < 0;
}

int main() {
    FILE *inputFile;
    char inputString[MAX_WORD_LENGTH];
    char *token;
    WordFrequency wordFrequencyArray[MAX_WORDS];
    int wordCount = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputString)!= EOF) {
        token = strtok(inputString, ",.!?;:");

        while (token!= NULL) {
            if (wordCount >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            strcpy(wordFrequencyArray[wordCount].word, token);
            wordFrequencyArray[wordCount].frequency = 1;

            wordCount++;

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencyArray, wordCount, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencyArray[i].word, wordFrequencyArray[i].frequency);
    }

    return 0;
}