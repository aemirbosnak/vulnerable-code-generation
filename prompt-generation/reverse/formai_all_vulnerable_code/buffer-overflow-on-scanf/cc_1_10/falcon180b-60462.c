//Falcon-180B DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_LINE_LENGTH], outputFileName[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

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
        fclose(inputFile);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        int wordIndex = 0;
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL && numWords < MAX_WORDS) {
            int wordLength = strlen(token);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long.\n", token);
                fclose(inputFile);
                fclose(outputFile);
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}