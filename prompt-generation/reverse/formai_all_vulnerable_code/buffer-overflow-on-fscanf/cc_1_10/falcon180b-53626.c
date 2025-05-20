//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_LENGTH_MAX 20

typedef struct {
    char word[WORD_LENGTH_MAX];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*) a;
    const WordFrequency* wordB = (const WordFrequency*) b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE* file, WordFrequency words[]) {
    char word[WORD_LENGTH_MAX];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) <= WORD_LENGTH_MAX - 1) {
            strcpy(words[0].word, word);
            words[0].frequency = 1;
        } else {
            printf("Error: Word \"%s\" is too long.\n", word);
        }
    }
}

void countWordFrequencies(WordFrequency words[], int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\t\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(file, words);
    fclose(file);

    countWordFrequencies(words, numWords);

    return 0;
}