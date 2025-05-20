//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_WORD_LENGTH];
    char outputFileName[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    WordTranslation words[MAX_WORDS];

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    fprintf(outputFile, "%s ", words[i].translation);
                    break;
                }
            }
            if (i == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }
                printf("Enter the translation for '%s': ", word);
                scanf("%s", words[numWords].translation);
                strcpy(words[numWords].word, word);
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}