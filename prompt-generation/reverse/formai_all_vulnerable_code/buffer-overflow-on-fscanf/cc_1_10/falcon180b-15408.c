//Falcon-180B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
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
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // remove newline character

        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, inputBuffer) == 0) {
                words[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: maximum number of words (%d) reached.\n", MAX_WORDS);
                return 1;
            }

            strcpy(words[numWords].word, inputBuffer);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}