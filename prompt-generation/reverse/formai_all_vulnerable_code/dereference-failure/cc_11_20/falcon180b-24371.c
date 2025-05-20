//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char fileName[100];
    char buffer[MAX_SENTENCE_LENGTH];
    int sentenceCount = 0;
    Sentence sentences[MAX_SENTENCES];

    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Copy the filename to a buffer
    strcpy(fileName, argv[1]);

    // Open the input file
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", fileName);
        return 1;
    }

    // Read the input file line by line
    while (fgets(buffer, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        // Remove any leading/trailing white spaces from the line
        int i, j;
        for (i = 0, j = strlen(buffer) - 1; i < j; i++, j--) {
            if (!isspace(buffer[i]) &&!isspace(buffer[j])) {
                break;
            }
        }
        if (i >= j) {
            continue;
        }
        buffer[j] = '\0';

        // Check if the sentence length exceeds the maximum limit
        if (strlen(buffer) > MAX_SENTENCE_LENGTH - 1) {
            printf("Warning: Sentence length exceeds maximum limit.\n");
            continue;
        }

        // Add the sentence to the array of sentences
        strcpy(sentences[sentenceCount].text, buffer);
        sentences[sentenceCount].length = strlen(buffer);
        sentenceCount++;

        // Check if the maximum number of sentences is reached
        if (sentenceCount >= MAX_SENTENCES) {
            break;
        }
    }

    // Close the input file
    fclose(inputFile);

    // Print the summary
    printf("Summary:\n");
    for (int i = 0; i < sentenceCount; i++) {
        printf("%s\n", sentences[i].text);
    }

    return 0;
}