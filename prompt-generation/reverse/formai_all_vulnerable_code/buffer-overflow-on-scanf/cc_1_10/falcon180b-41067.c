//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main() {
    FILE *inputFile;
    char inputFileName[100];
    char line[1000];
    int numWords = 0;
    struct WordFrequency wordFrequencies[MAX_NUM_WORDS];

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }
                strncpy(wordFrequencies[numWords].word, word, MAX_WORD_LENGTH);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    printf("Enter the output file name: ");
    scanf("%s", inputFileName);

    FILE *outputFile = fopen(inputFileName, "w");

    if (outputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(outputFile);

    return 0;
}