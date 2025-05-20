//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];
    char *token;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].count = 1;

            numWords++;

            token = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}