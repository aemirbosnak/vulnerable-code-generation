//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    int numSentences = 0;
    Sentence sentences[MAX_SENTENCES];

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
        fclose(inputFile);
        exit(1);
    }

    while (fgets(sentences[numSentences].text, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        sentences[numSentences].length = strlen(sentences[numSentences].text);
        numSentences++;
    }

    fclose(inputFile);
    fclose(outputFile);

    int i, j;
    for (i = 0; i < numSentences; i++) {
        for (j = 0; j < sentences[i].length; j++) {
            if (isalpha(sentences[i].text[j])) {
                fprintf(outputFile, "%c", toupper(sentences[i].text[j]));
            }
        }
        fprintf(outputFile, " ");
    }

    fclose(outputFile);

    printf("Summary generated successfully!\n");

    return 0;
}