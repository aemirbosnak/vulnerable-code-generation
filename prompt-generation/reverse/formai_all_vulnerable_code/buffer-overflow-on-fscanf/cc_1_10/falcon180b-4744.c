//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// structure to hold word frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// function to compare two word frequency structures
int compareFrequency(const void *a, const void *b) {
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

// function to read input file and count word frequencies
void countWords(FILE *inputFile, WordFrequency *wordFrequencies, int numWords) {
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int i;

    // read words from input file
    while (fscanf(inputFile, "%s", word)!= EOF) {
        // convert word to lowercase
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        wordLength = strlen(word);

        // check if word is already in wordFrequencies
        bool found = false;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                found = true;
                break;
            }
        }

        // add new word to wordFrequencies if not found
        if (!found) {
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }
    }
}

// function to print word frequencies in descending order
void printFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareFrequency);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    countWords(inputFile, wordFrequencies, numWords);

    printFrequencies(wordFrequencies, numWords);

    fclose(inputFile);
    return 0;
}