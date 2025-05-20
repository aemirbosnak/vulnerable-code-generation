//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
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
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    WordTranslation *wordTranslations = malloc(MAX_WORDS * sizeof(WordTranslation));

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read input file and store words and translations in an array
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");
        if (word == NULL || translation == NULL) {
            printf("Error parsing input file.\n");
            exit(1);
        }
        strcpy(wordTranslations[numWords].word, word);
        strcpy(wordTranslations[numWords].translation, translation);
        numWords++;
    }

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write translations to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", wordTranslations[i].word, wordTranslations[i].translation);
    }

    // Close files and free memory
    fclose(inputFile);
    fclose(outputFile);
    free(wordTranslations);

    return 0;
}