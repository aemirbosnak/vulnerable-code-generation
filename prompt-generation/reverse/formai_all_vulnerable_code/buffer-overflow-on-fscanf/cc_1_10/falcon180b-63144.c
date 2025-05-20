//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (wordLength >= MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
        strcpy(wordFrequencies[wordLength].word, word);
        wordFrequencies[wordLength].count = 1;
        wordLength++;
    }
}

void countWords(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    readFile(file, wordFrequencies);
    countWords(wordFrequencies, numWords);
    fclose(file);
    return 0;
}