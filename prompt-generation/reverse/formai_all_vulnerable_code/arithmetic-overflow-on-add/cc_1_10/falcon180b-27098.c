//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define NUM_WORDS 1000
#define NUM_SYMBOLS 26

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void generateRandomWord(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = 'a' + rand() % NUM_SYMBOLS;
    }
}

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *) a;
    const WordFrequency *wordB = (const WordFrequency *) b;

    return wordA->frequency - wordB->frequency;
}

int main() {
    FILE *inputFile;
    char inputWord[MAX_WORD_LENGTH];
    int totalWords = 0;
    WordFrequency wordFrequencies[NUM_WORDS];

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read words from input file and count their frequencies
    while (fscanf(inputFile, "%s", inputWord)!= EOF) {
        totalWords++;

        for (int i = 0; i < NUM_WORDS; i++) {
            if (strcmp(inputWord, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
    }

    // Sort words by frequency
    qsort(wordFrequencies, NUM_WORDS, sizeof(WordFrequency), compareWords);

    // Print top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < totalWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}