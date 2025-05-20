//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j, k;
    FILE *inputFile, *outputFile;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read input file and count word frequencies
    while (fscanf(inputFile, "%s", input)!= EOF) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                return 1;
            }
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
        }
    }

    // Sort words by frequency
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write words to output file
    for (i = 0; i < numWords; i++) {
        k = 0;
        while (k < MAX_WORD_LENGTH && words[i].word[k]!= '\0') {
            if (isalpha(words[i].word[k])) {
                output[k] = tolower(words[i].word[k]);
                k++;
            } else {
                output[k] = '\0';
                break;
            }
        }
        fprintf(outputFile, "%s %d\n", output, words[i].count);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}