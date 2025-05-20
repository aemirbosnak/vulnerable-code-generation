//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    char *word, *translation;
    WordTranslation wordTranslations[MAX_WORDS];
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read words and translations from input file
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        word = strtok(line, ",");
        translation = strtok(NULL, ",");

        // Add word and translation to array
        strcpy(wordTranslations[numWords].word, word);
        strcpy(wordTranslations[numWords].translation, translation);
        numWords++;
    }

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write translations to output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %s\n", wordTranslations[i].word, wordTranslations[i].translation);
    }

    // Close output file
    fclose(outputFile);

    return 0;
}