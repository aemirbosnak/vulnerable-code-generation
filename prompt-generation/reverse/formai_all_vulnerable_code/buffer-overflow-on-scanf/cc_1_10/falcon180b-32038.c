//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LEN 100
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LEN];
    int len;
} Sentence;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    int numSentences = 0, i;
    Sentence sentences[MAX_SENTENCES];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
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

    while (fgets(sentences[numSentences].text, MAX_SENTENCE_LEN, inputFile)!= NULL) {
        sentences[numSentences].len = strlen(sentences[numSentences].text);
        numSentences++;
    }

    fclose(inputFile);

    for (i = 0; i < numSentences; i++) {
        fprintf(outputFile, "%s\n", sentences[i].text);
    }

    fclose(outputFile);

    return 0;
}