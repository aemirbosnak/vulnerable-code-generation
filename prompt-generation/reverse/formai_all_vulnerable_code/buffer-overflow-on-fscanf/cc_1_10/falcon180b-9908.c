//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} TranslationPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    int numPairs = 0;
    TranslationPair pairs[MAX_WORDS];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the name of the input file: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    printf("Please enter the name of the output file: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s %s", pairs[numPairs].english, pairs[numPairs].alien)!= EOF) {
        numPairs++;
    }

    printf("Translating %d pairs of words...\n", numPairs);

    for (int i = 0; i < numPairs; i++) {
        fprintf(outputFile, "%s %s\n", pairs[i].english, pairs[i].alien);
    }

    printf("Translation complete!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}