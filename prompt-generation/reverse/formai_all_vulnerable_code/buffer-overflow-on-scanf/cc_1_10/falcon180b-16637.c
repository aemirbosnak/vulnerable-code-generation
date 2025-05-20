//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    Sentence sentences[MAX_SENTENCES];
    int numSentences = 0, i;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(sentences[numSentences].text, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        numSentences++;
        if (numSentences >= MAX_SENTENCES) {
            printf("Error: Input file is too large.\n");
            exit(1);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    for (i = 0; i < numSentences; i++) {
        char *token = strtok(sentences[i].text, " ");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                fprintf(outputFile, "%s ", token);
            }
            token = strtok(NULL, " ");
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    printf("Summary created successfully.\n");

    return 0;
}