//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordTranslation translations[MAX_WORDS];
    int numTranslations = 0;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Read input file and store translations
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numTranslations >= MAX_WORDS) {
            printf("Error: too many translations.\n");
            return 1;
        }

        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        strcpy(translations[numTranslations].word, word);
        strcpy(translations[numTranslations].translation, translation);

        numTranslations++;
    }

    // Write translations to output file
    for (int i = 0; i < numTranslations; i++) {
        fprintf(outputFile, "%s %s\n", translations[i].word, translations[i].translation);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}