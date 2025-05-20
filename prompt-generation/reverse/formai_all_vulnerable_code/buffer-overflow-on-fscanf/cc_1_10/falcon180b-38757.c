//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_NUM_WORDS 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_SIZE];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[], int numWords) {
    char word[MAX_WORD_SIZE];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void countWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
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

    WordFrequency words[MAX_NUM_WORDS];
    int numWords = 0;

    readWords(inputFile, words, MAX_NUM_WORDS);
    countWords(words, numWords);
    printWords(words, numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}