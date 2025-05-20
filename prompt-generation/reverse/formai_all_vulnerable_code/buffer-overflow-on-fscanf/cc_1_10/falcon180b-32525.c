//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000 // Maximum number of words to store
#define MAX_WORD_LENGTH 100 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency* wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Word '%s' is too long (max length is %d).\n", word, MAX_WORD_LENGTH);
            continue;
        }

        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                break;
            }
        }

        if (numWords >= MAX_WORDS) {
            printf("Reached maximum number of words (%d).\n", MAX_WORDS);
            break;
        }

        strcpy(wordFrequencies[numWords].word, word);
        wordFrequencies[numWords].count = 1;
        numWords++;
    }

    fclose(file);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}