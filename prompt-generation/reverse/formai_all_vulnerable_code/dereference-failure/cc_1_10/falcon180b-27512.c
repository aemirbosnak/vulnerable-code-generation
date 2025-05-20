//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
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
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordTranslation words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[numWords].word, line);
        words[numWords].translation[0] = '\0';
        numWords++;
    }

    for (i = 0; i < numWords; i++) {
        printf("Enter the translation for %s: ", words[i].word);
        fgets(words[i].translation, MAX_WORD_LENGTH, stdin);
        words[i].translation[strcspn(words[i].translation, "\n")] = '\0';
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s = %s\n", words[i].word, words[i].translation);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}