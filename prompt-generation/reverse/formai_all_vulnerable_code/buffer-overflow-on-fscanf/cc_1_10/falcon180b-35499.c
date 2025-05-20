//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *)a;
    WordCount *wordCountB = (WordCount *)b;
    return strcmp(wordCountA->word, wordCountB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char inputBuffer[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        if (numWords >= MAX_WORD_LENGTH) {
            printf("Error: Too many words in input file.\n");
            fclose(inputFile);
            return 1;
        }
        wordCounts[numWords].word = strdup(inputBuffer);
        wordCounts[numWords].count = 1;
        numWords++;
    }

    fclose(inputFile);
    printWordCounts(wordCounts, numWords);

    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }

    return 0;
}