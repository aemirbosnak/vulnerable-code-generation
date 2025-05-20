//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
} TranslationPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputLine[MAX_LINE_LEN];
    char *word;
    TranslationPair *translationPairs;
    int numTranslationPairs = 0;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read translation pairs from input file
    translationPairs = (TranslationPair *) malloc(sizeof(TranslationPair));
    while (fgets(inputLine, MAX_LINE_LEN, inputFile)!= NULL) {
        word = strtok(inputLine, " ");
        strcpy(translationPairs[numTranslationPairs].english, word);
        word = strtok(NULL, " ");
        strcpy(translationPairs[numTranslationPairs].cat, word);
        numTranslationPairs++;
        if (numTranslationPairs >= MAX_LINE_LEN) {
            printf("Error: too many translation pairs in input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
    }

    // Translate input file to C Cat Language
    fseek(inputFile, 0, SEEK_SET);
    while (fgets(inputLine, MAX_LINE_LEN, inputFile)!= NULL) {
        char *pos = inputLine;
        while ((word = strtok(pos, " "))!= NULL) {
            int i;
            for (i = 0; i < numTranslationPairs; i++) {
                if (strcmp(word, translationPairs[i].english) == 0) {
                    fprintf(outputFile, "%s ", translationPairs[i].cat);
                    break;
                }
            }
            if (i == numTranslationPairs) {
                fprintf(outputFile, "%s ", word);
            }
            pos = NULL;
        }
        fprintf(outputFile, "\n");
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}