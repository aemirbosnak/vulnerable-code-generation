//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    char input[MAX_WORD_LENGTH];
    FILE *inputFile;
    FILE *outputFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }

        for (i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fprintf(outputFile, "Word\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}