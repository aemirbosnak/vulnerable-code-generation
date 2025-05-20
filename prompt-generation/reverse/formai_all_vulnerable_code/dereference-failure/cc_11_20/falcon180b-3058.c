//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(line, MAX_WORD_LEN, inputFile)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                // New word
                if (numWords == MAX_WORDS) {
                    printf("Error: too many unique words.\n");
                    exit(1);
                }
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Sort words by frequency
    for (i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Write output file
    fprintf(outputFile, "Word\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}