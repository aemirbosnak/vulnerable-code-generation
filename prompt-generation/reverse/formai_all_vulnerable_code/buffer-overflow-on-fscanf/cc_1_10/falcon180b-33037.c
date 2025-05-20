//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        int wordIndex = -1;

        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex == -1) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                fclose(inputFile);
                return 1;
            }

            strncpy(wordFrequencies[numWords].word, word, MAX_WORD_LENGTH);
            wordFrequencies[numWords].count = 1;
            numWords++;
        } else {
            wordFrequencies[wordIndex].count++;
        }
    }

    fclose(inputFile);
    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}