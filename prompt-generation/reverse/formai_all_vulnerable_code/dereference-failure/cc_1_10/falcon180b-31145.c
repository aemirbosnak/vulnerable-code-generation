//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH_MAX 100

typedef struct {
    char word[WORD_LENGTH_MAX];
    int frequency;
} WordFrequency;

bool compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*) a;
    const WordFrequency* wordB = (const WordFrequency*) b;
    return strcmp(wordA->word, wordB->word) < 0;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    WordFrequency* words = malloc(MAX_WORDS * sizeof(WordFrequency));
    if (words == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(2);
    }

    int numWords = 0;
    char word[WORD_LENGTH_MAX];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            exit(3);
        }

        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    free(words);
    fclose(file);

    return 0;
}