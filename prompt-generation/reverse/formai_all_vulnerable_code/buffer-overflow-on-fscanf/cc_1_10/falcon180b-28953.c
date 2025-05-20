//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    int inputBufferIndex = 0;
    int numWords = 0;

    WordFrequency *wordFrequencies = (WordFrequency *) malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    memset(wordFrequencies, 0, MAX_NUM_WORDS * sizeof(WordFrequency));

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        int i;
        for (i = 0; i < inputBufferIndex; i++) {
            if (strcmp(inputBuffer, inputBuffer + i) == 0) {
                break;
            }
        }

        if (i == inputBufferIndex) {
            strcpy(inputBuffer + inputBufferIndex, inputBuffer);
            inputBufferIndex++;
            numWords++;
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(inputFile);
    free(wordFrequencies);

    return 0;
}