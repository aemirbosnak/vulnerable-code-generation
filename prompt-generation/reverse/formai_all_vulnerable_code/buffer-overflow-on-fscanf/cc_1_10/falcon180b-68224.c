//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
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
    FILE *inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        word[strcspn(word, ",.?!;:\"'")] = '\0'; // Remove punctuation from end of word

        int wordIndex = 0;
        while (wordIndex < numWords && strcmp(wordFrequencies[wordIndex].word, word)!= 0) {
            wordIndex++;
        }

        if (wordIndex == numWords) {
            strcpy(wordFrequencies[numWords].word, word);
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