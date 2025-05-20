//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* w1 = a;
    const WordFrequency* w2 = b;

    return strcmp(w1->word, w2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE* inputFile;
    FILE* outputFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    inputFile = fopen(input, "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            fclose(inputFile);
            return 1;
        }

        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(outputFile);

    return 0;
}