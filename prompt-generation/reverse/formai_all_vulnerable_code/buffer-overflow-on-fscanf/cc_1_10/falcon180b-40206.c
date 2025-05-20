//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
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

void readWords(FILE* file, WordFrequency words[], int* numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
        WordFrequency* currentWord = &words[*numWords];
        strcpy(currentWord->word, word);
        currentWord->frequency = 1;
        (*numWords)++;
    }
}

void countWords(WordFrequency words[], int numWords, FILE* outputFile) {
    for (int i = 0; i < numWords; i++) {
        WordFrequency* currentWord = &words[i];
        fprintf(outputFile, "%s: %d\n", currentWord->word, currentWord->frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    int numWords = 0;
    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words, &numWords);

    countWords(words, numWords, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}