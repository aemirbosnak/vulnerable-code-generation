//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(FILE *file, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].count = 1;
        (*numWords)++;
    }
}

void countWords(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    FILE *outputFile = fopen("word_frequency.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    fprintf(outputFile, "Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    readWords(file, words, &numWords);
    countWords(words, numWords);
    return 0;
}