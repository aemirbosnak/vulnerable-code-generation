//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_WORD_LENGTH], outputFileName[MAX_WORD_LENGTH];
    int numWords = 0;
    WordTranslation words[MAX_WORDS];

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read words and translations from input file
    while (fscanf(inputFile, "%s %s", words[numWords].word, words[numWords].translation)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
    }
    fclose(inputFile);

    // Write translations to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].word, words[i].translation);
    }
    fclose(outputFile);

    printf("Translation complete.\n");

    return 0;
}