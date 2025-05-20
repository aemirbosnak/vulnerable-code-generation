//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;
    return strcmp(word1->word, word2->word);
}

void printTopFrequentWords(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    // Read input file
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Count word frequencies
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character
        tolower(word); // Convert to lowercase
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }
    }

    // Sort and print top frequent words
    printTopFrequentWords(wordFrequencies, numWords);

    // Close input file
    fclose(inputFile);

    return 0;
}