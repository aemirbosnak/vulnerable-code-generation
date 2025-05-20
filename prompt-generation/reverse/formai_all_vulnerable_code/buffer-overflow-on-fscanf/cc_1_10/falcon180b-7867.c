//Falcon-180B DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Reached maximum number of words.\n");
            fclose(inputFile);
            return 1;
        }

        wordFrequencies[numWords].word[0] = tolower(inputBuffer[0]);
        strcpy(wordFrequencies[numWords].word + 1, inputBuffer + 1);
        wordFrequencies[numWords].count = 1;
        numWords++;
    }

    fclose(inputFile);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}