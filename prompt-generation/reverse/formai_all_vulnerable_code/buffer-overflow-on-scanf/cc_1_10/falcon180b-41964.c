//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char text[10000];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0, totalWords = 0;
    FILE *inputFile;
    WordFrequency wordFrequencies[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", text);

    inputFile = fopen(text, "r");
    if (inputFile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        totalWords++;

        if (wordCount >= MAX_WORDS) {
            printf("Error: reached maximum number of words.\n");
            exit(1);
        }

        wordCount++;
        strcpy(wordFrequencies[wordCount - 1].word, word);
        wordFrequencies[wordCount - 1].count = 1;
    }

    fclose(inputFile);

    qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}