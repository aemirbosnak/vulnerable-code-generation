//Falcon-180B DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        int wordIndex = 0;
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL && wordIndex < MAX_WORDS) {
            strcpy(wordCounts[wordIndex].word, token);
            wordCounts[wordIndex].count = 1;
            wordIndex++;

            token = strtok(NULL, ",.?!;:");
        }

        numWords = wordIndex;
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}