//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].frequency = 1;
        (*numWords)++;
    }
}

void countWords(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printWords(WordFrequency *words, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s\t%d\n", words[i].word, words[i].frequency);
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
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(inputFile, words, &numWords);
    countWords(words, numWords);
    printWords(words, numWords);

    fprintf(outputFile, "Total words: %d\n", numWords);
    fprintf(outputFile, "Unique words: %d\n", numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}