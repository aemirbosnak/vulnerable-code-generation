//Falcon-180B DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencyTable[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word) == 1) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words exceeded.\n");
            break;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordFrequencyTable[i].word) == 0) {
                wordFrequencyTable[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(wordFrequencyTable[numWords].word, word);
            wordFrequencyTable[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(wordFrequencyTable, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].frequency);
    }

    return 0;
}