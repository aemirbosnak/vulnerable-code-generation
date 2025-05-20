//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
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
    FILE *inputFile;
    FILE *outputFile;
    char inputFileName[100];
    char outputFileName[100];
    int numWords;
    WordTranslation words[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    numWords = 0;
    while (fscanf(inputFile, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Enter the translations for the words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", words[i].translation);
    }

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");

    while (fscanf(inputFile, "%s", words[0].word)!= EOF) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, words[0].word) == 0) {
                fprintf(outputFile, "%s ", words[i].translation);
                break;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Translation complete!\n");

    return 0;
}