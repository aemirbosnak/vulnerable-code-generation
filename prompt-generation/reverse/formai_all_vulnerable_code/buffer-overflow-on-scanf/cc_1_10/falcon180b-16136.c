//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    Word words[MAX_WORDS];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            printf("Enter translation for '%s': ", word);
            scanf("%s", words[numWords].translation);
            numWords++;
            word = strtok(NULL, " ");
        }
    }

    fprintf(outputFile, "C Cat Language Translator\n");
    fprintf(outputFile, "Input file: %s\n", inputFileName);
    fprintf(outputFile, "Output file: %s\n", outputFileName);
    fprintf(outputFile, "Number of words: %d\n", numWords);

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "Word %d:\n", i + 1);
        fprintf(outputFile, "  English: %s\n", words[i].word);
        fprintf(outputFile, "  C Cat:   %s\n", words[i].translation);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Translation complete.\n");

    return 0;
}