//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: protected
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
    char inputFileName[50], outputFileName[50];
    char line[100];
    int numWords = 0;
    WordTranslation words[MAX_WORDS];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        fclose(inputFile);
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words exceeded\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(1);
            }
            strcpy(words[numWords].word, word);
            printf("Enter translation for %s: ", word);
            fgets(words[numWords].translation, sizeof(words[numWords].translation), stdin);
            numWords++;
            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Translating...\n");

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
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
                fprintf(outputFile, "%s ", word);
            }
            word = strtok(NULL, " ");
        }
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Translation complete\n");

    return 0;
}