//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[], int *numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
    *numWords = i;
}

void countWords(FILE *file, WordFrequency words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    WordFrequency words[MAX_WORDS];
    int numWords;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    readWords(inputFile, words, &numWords);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    countWords(inputFile, words, numWords);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    printWords(words, numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}