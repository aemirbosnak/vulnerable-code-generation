//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 64
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordCountA = a;
    const WordCount* wordCountB = b;

    return strcmp(wordCountA->word, wordCountB->word);
}

int main() {
    FILE* inputFile;
    FILE* dictionaryFile;
    char word[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char dictionaryWord[MAX_WORD_LENGTH];
    WordCount wordCounts[1000];
    int numWords = 0;
    int numMisspelledWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read words from input file
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= 1000) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 0;
        numWords++;
    }

    // Close input file
    fclose(inputFile);

    // Open dictionary file
    dictionaryFile = fopen(DICTIONARY_FILE, "r");
    if (dictionaryFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    // Read words from dictionary file
    while (fscanf(dictionaryFile, "%s", dictionaryWord)!= EOF) {
        qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
        int i, j;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, dictionaryWord) == 0) {
                break;
            }
        }
        if (i == numWords) {
            printf("%s is not in the dictionary.\n", word);
            numMisspelledWords++;
        } else {
            wordCounts[i].count++;
        }
    }

    // Close dictionary file
    fclose(dictionaryFile);

    // Print misspelled words with their frequencies
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].count == 0) {
            printf("%s is not in the dictionary.\n", wordCounts[i].word);
        }
    }

    // Print number of misspelled words
    printf("Number of misspelled words: %d\n", numMisspelledWords);

    return 0;
}