//Falcon-180B DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWordFrequency(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer) == 1) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, inputBuffer) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(wordFrequencies[numWords].word, inputBuffer);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWordFrequency);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    return 0;
}