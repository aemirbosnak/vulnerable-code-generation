//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} TranslationPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    int numPairs;
    TranslationPair pairs[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

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

    numPairs = 0;
    while (fscanf(inputFile, "%s %s", pairs[numPairs].english, pairs[numPairs].alien)!= EOF) {
        numPairs++;
    }

    fclose(inputFile);

    fprintf(outputFile, "Alien Language Translator\n");
    fprintf(outputFile, "=========================\n");
    fprintf(outputFile, "Number of translation pairs: %d\n", numPairs);
    for (int i = 0; i < numPairs; i++) {
        fprintf(outputFile, "%s -> %s\n", pairs[i].english, pairs[i].alien);
    }

    fclose(outputFile);

    return 0;
}