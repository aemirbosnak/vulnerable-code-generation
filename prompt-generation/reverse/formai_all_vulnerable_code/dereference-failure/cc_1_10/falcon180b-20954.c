//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LEN];
    WordTranslation *wordTranslations[MAX_WORDS];
    int numTranslations = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file and store translations in an array
    while (fgets(line, MAX_WORD_LEN, inputFile)!= NULL) {
        WordTranslation *newTranslation = malloc(sizeof(WordTranslation));
        strcpy(newTranslation->word, line);
        strcpy(newTranslation->translation, "");
        wordTranslations[numTranslations++] = newTranslation;
    }

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Prompt user for translations and write to output file
    for (int i = 0; i < numTranslations; i++) {
        printf("Enter translation for '%s': ", wordTranslations[i]->word);
        fgets(wordTranslations[i]->translation, MAX_WORD_LEN, stdin);
        fprintf(outputFile, "%s %s\n", wordTranslations[i]->word, wordTranslations[i]->translation);
    }

    // Close output file
    fclose(outputFile);

    return 0;
}