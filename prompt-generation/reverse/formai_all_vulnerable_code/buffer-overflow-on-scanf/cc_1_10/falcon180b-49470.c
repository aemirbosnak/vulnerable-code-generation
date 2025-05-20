//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    Sentence sentences[MAX_SENTENCES];
    int numSentences = 0;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
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

    // Read input file and store sentences in array
    char ch;
    int sentenceIndex = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (ch == '.' || ch == '?' || ch == '!') {
            sentences[sentenceIndex].length = strlen(sentences[sentenceIndex].text);
            sentenceIndex++;
        } else {
            strncat(sentences[sentenceIndex].text, &ch, 1);
        }
    }
    sentences[sentenceIndex].length = strlen(sentences[sentenceIndex].text);
    numSentences = sentenceIndex + 1;

    // Summarize sentences
    int summaryLength = 0;
    for (int i = 0; i < numSentences; i++) {
        if (summaryLength + sentences[i].length <= MAX_SENTENCE_LENGTH) {
            strncat(sentences[0].text, sentences[i].text, sentences[i].length);
            summaryLength += sentences[i].length;
        }
    }
    sentences[0].length = summaryLength;

    // Write summary to output file
    fprintf(outputFile, "%s", sentences[0].text);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}