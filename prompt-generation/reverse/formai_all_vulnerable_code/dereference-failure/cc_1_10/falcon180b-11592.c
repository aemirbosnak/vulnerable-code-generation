//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (numWords >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                return 1;
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}