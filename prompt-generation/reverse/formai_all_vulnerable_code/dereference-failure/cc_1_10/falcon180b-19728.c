//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    Word words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            return 1;
        }
        strcpy(words[numWords].word, line);
        numWords++;
    }

    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, "cat") == 0) {
            strcpy(words[i].translation, "gato");
        } else if (strcmp(words[i].word, "dog") == 0) {
            strcpy(words[i].translation, "perro");
        } else if (strcmp(words[i].word, "hello") == 0) {
            strcpy(words[i].translation, "hola");
        } else {
            strcpy(words[i].translation, "unknown");
        }
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s -> %s\n", words[i].word, words[i].translation);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}