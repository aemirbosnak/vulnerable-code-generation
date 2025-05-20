//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000
#define MAX_WORD_COUNT 100000

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
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    WordFrequency* wordFrequencies = malloc(sizeof(WordFrequency) * MAX_WORD_COUNT);
    if (wordFrequencies == NULL) {
        printf("Error allocating memory for word frequencies\n");
        exit(1);
    }

    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORD_COUNT) {
            printf("Error: maximum word count exceeded\n");
            exit(1);
        }

        WordFrequency* newFrequency = malloc(sizeof(WordFrequency));
        if (newFrequency == NULL) {
            printf("Error allocating memory for new word frequency\n");
            exit(1);
        }

        strcpy(newFrequency->word, word);
        newFrequency->count = 1;

        int i = 0;
        while (i < wordCount && strcmp(wordFrequencies[i].word, word)!= 0) {
            i++;
        }

        if (i < wordCount) {
            wordFrequencies[i].count++;
        } else {
            wordFrequencies[wordCount++] = *newFrequency;
            qsort(wordFrequencies, wordCount, sizeof(WordFrequency), compareWords);
        }

        free(newFrequency);
    }

    fclose(inputFile);

    printf("Word\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    return 0;
}