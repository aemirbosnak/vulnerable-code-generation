//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *inputFile, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void countWords(WordFrequency words[], int numWords) {
    int i, j;

    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    readWords(inputFile, words);
    fclose(inputFile);

    countWords(words, numWords);
    printWords(words, numWords);

    return 0;
}