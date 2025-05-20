//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[100];
    int numWords = 0, i;
    WordTranslation words[MAX_WORDS];

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read input file and store words and translations in array
    while (fgets(line, 100, inputFile)!= NULL) {
        char *word = strtok(line, " \t\r\n");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }
            strcpy(words[numWords].word, word);
            word = strtok(NULL, " \t\r\n");
            if (word == NULL) {
                strcpy(words[numWords].translation, "");
            } else {
                strcpy(words[numWords].translation, word);
            }
            numWords++;
        }
    }

    // Write translations to output file
    fprintf(outputFile, "Translated words:\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s -> %s\n", words[i].word, words[i].translation);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}