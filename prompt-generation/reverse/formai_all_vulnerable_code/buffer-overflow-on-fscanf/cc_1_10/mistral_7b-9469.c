//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

typedef struct {
    char word[WORD_LENGTH];
    int length;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *inputFile = fopen(INPUT_FILE, "r");
    FILE *outputFile = fopen(OUTPUT_FILE, "w");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    Word words[MAX_WORDS];
    int numWords = 0;

    char currentWord[WORD_LENGTH];
    int currentLength = 0;

    while (fscanf(inputFile, "%s%n", currentWord, &currentLength) != EOF) {
        if (numWords >= MAX_WORDS) {
            fprintf(outputFile, "Max number of words reached. Exiting...\n");
            break;
        }

        toLowerCase(currentWord);

        int i;
        for (i = 0; currentWord[i] != '\0'; i++) {
            if (!isalpha(currentWord[i]) && !isDelimiter(currentWord[i])) {
                currentWord[i] = '\0';
                break;
            }
        }

        if (i > currentLength) {
            currentLength = i;
        }

        words[numWords].length = currentLength + 1;
        strncpy(words[numWords].word, currentWord, words[numWords].length);
        numWords++;
    }

    fprintf(outputFile, "Number of words: %d\n", numWords);

    double totalLength = 0;
    for (int i = 0; i < numWords; i++) {
        totalLength += words[i].length;
    }

    double averageLength = totalLength / numWords;
    fprintf(outputFile, "Average word length: %.2f\n", averageLength);

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%.*s (%d characters)\n", words[i].length, words[i].word, words[i].length);
    }

    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}