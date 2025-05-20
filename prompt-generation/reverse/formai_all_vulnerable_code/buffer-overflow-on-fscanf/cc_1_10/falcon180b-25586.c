//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, char words[MAX_WORDS][MAX_WORD_LENGTH], int *numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    *numWords = i;
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char * const *)a, *(char * const *)b);
}

void countWordFrequencies(char words[MAX_WORDS][MAX_WORD_LENGTH], int numWords, WordFrequency freq[MAX_WORDS]) {
    int i;

    for (i = 0; i < numWords; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0)
                break;
        }

        if (j == i) {
            strcpy(freq[i].word, words[i]);
            freq[i].count = 1;
        } else {
            freq[j].count++;
        }
    }
}

void printWordFrequencies(WordFrequency freq[MAX_WORDS], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", freq[i].word, freq[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords, i;
    WordFrequency freq[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readWords(file, words, &numWords);

    for (i = 0; i < numWords; i++) {
        strcpy(freq[i].word, words[i]);
        freq[i].count = 1;
    }

    qsort(freq, numWords, sizeof(WordFrequency), compareWords);

    printWordFrequencies(freq, numWords);

    return 0;
}