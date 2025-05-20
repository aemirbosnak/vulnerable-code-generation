//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordTranslation;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[1000];
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
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words in input file.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            printf("Enter the translation for '%s': ", word);
            fgets(words[numWords].translation, sizeof(words[numWords].translation), stdin);
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].word, words[i].translation);
    }

    fclose(outputFile);

    printf("Translation complete.\n");

    return 0;
}