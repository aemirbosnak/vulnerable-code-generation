//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Read input file and count word occurrences
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    return 1;
                }
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    // Write output file
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Close files and exit
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}