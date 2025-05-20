//Falcon-180B DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
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

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // remove newline character

        for (int i = 0; i < numWords; i++) {
            if (strcmp(inputBuffer, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }

        if (numWords == MAX_WORDS) {
            printf("Error: maximum number of words reached.\n");
            exit(1);
        } else if (numWords == 0) {
            strcpy(wordFrequencies[numWords].word, inputBuffer);
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}