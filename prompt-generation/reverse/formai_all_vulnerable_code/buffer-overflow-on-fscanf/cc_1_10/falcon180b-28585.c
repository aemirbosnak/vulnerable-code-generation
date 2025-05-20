//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void initWordFrequency(WordFrequency* wordFrequency) {
    wordFrequency->frequency = 0;
    wordFrequency->word[0] = '\0';
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void updateWordFrequency(WordFrequency* wordFrequency, const char* word) {
    strcpy(wordFrequency->word, word);
    wordFrequency->frequency++;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    WordFrequency* wordFrequencies = (WordFrequency*)malloc(MAX_WORDS * sizeof(WordFrequency));
    if (wordFrequencies == NULL) {
        printf("Error allocating memory for word frequencies\n");
        fclose(file);
        return 1;
    }

    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached\n");
            fclose(file);
            free(wordFrequencies);
            return 1;
        }

        initWordFrequency(&wordFrequencies[numWords]);
        strcpy(wordFrequencies[numWords].word, word);
        numWords++;
    }

    fclose(file);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);
    return 0;
}