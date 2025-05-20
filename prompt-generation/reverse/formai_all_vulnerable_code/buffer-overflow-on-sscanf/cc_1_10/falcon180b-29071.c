//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordPair wordPair;
    int numWords = 0;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }

    // Read input file and store word pairs in an array
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of word pairs exceeded.\n");
            exit(1);
        }
        sscanf(line, "%s %s", wordPair.word, wordPair.translation);
        numWords++;
    }
    fclose(inputFile);

    // Translate the word pairs and write to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", wordPair.word, wordPair.translation);
    }
    fclose(outputFile);

    printf("Translation complete!\n");
    return 0;
}