//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    int numTokens = 0;
    WordCount *wordCounts = calloc(MAX_TOKENS, sizeof(WordCount));

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", input)!= EOF) {
        numTokens++;
    }

    rewind(inputFile);
    int i = 0;
    while (fscanf(inputFile, "%s", input)!= EOF) {
        if (i >= MAX_TOKENS) {
            printf("Error: Too many unique words.\n");
            exit(1);
        }
        if (strlen(input) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
        char *word = strdup(input);
        wordCounts[i].word = word;
        wordCounts[i].count = 1;
        i++;
    }

    for (i = 0; i < numTokens; i++) {
        if (strcmp(input, "cat") == 0) {
            strcpy(output, "meow");
        } else if (strcmp(input, "dog") == 0) {
            strcpy(output, "woof");
        } else if (strcmp(input, "bird") == 0) {
            strcpy(output, "chirp");
        } else {
            for (int j = 0; j < numTokens; j++) {
                if (strcmp(wordCounts[j].word, input) == 0) {
                    wordCounts[j].count++;
                    break;
                }
            }
        }
        printf("%s -> %s\n", input, output);
    }

    fclose(inputFile);
    return 0;
}