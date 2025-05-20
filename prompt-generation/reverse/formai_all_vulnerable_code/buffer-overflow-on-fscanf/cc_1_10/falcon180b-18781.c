//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency* frequencies, int numWords) {
    qsort(frequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character

        int wordIndex = 0;
        while (wordIndex < numWords && strcmp(frequencies[wordIndex].word, word)!= 0) {
            wordIndex++;
        }

        if (wordIndex == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Max number of words reached.\n");
                break;
            }

            strcpy(frequencies[numWords].word, word);
            frequencies[numWords].count = 1;
            numWords++;
        } else {
            frequencies[wordIndex].count++;
        }
    }

    fclose(inputFile);

    printWordFrequency(frequencies, numWords);

    return 0;
}