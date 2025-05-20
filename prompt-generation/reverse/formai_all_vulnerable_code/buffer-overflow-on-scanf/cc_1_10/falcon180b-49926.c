//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    Word words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }

        char *word = strtok(line, " ");
        while (word!= NULL) {
            strcpy(words[numWords].english, word);
            printf("Enter the translation for '%s': ", word);
            scanf("%s", words[numWords].cat);
            numWords++;

            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].english, words[i].cat);
    }

    fclose(outputFile);
    printf("Translation completed successfully!\n");

    return 0;
}