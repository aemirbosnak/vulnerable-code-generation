//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    int numWords = 0;
    Word words[MAX_WORDS];

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Read English words from input file
    while (fscanf(inputFile, "%s", words[numWords].english)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(1);
        }
    }
    fclose(inputFile);

    // Translate English words to alien language
    for (int i = 0; i < numWords; i++) {
        strcpy(words[i].alien, "Alien language translation of ");
        strcat(words[i].alien, words[i].english);
    }

    // Write alien words to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i].alien);
    }

    fclose(outputFile);

    printf("Translation complete.\n");

    return 0;
}