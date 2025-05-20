//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char line[100];
    int numWords = 0;
    WordPair words[MAX_WORDS];

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

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v.?!:;,()[]{}<>");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            printf("Enter the translation for '%s': ", word);
            scanf("%s", words[numWords].translation);
            numWords++;
            word = strtok(NULL, " \t\n\r\f\v.?!:;,()[]{}<>");
        }
    }

    fprintf(outputFile, "Meow = %s\n", "Hello");
    fprintf(outputFile, "Purr = %s\n", "Goodbye");

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s = %s\n", words[i].word, words[i].translation);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}