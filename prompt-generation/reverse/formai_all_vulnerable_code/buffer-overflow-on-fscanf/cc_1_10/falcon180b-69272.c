//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000 // maximum number of words
#define MAX_WORD_LENGTH 100 // maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWord(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        int i = 0;
        while (i < MAX_WORD_LENGTH && wordFrequencies[i].word[0]!= '\0') {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
            i++;
        }
        if (i == MAX_WORD_LENGTH) {
            printf("Warning: maximum number of words reached.\n");
        }
    }
}

void writeWordFrequencies(FILE *file, WordFrequency *wordFrequencies) {
    qsort(wordFrequencies, MAX_WORD_LENGTH, sizeof(WordFrequency), compareWord);
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (wordFrequencies[i].word[0]!= '\0') {
            fprintf(file, "%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        return 1;
    }
    WordFrequency wordFrequencies[MAX_WORD_LENGTH];
    memset(wordFrequencies, 0, sizeof(wordFrequencies));
    readWords(inputFile, wordFrequencies);
    writeWordFrequencies(outputFile, wordFrequencies);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}