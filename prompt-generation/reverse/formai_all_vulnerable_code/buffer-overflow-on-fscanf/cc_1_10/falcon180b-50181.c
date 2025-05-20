//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;
    return strcmp(word1->word, word2->word);
}

void readWords(FILE *inputFile, WordFrequency *wordFrequencies, int *numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        WordFrequency *currentWord = &wordFrequencies[*numWords];
        strcpy(currentWord->word, word);
        currentWord->frequency = 1;
        (*numWords)++;
    }
}

void countWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
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
        printf("Error: Could not open input file.\n");
        return 1;
    }
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    readWords(inputFile, wordFrequencies, &numWords);
    countWordFrequencies(wordFrequencies, numWords);
    fclose(inputFile);
    return 0;
}