//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void countWords(WordFrequency words[MAX_WORDS]) {
    int i, j;
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);

    for (i = 0; i < MAX_WORDS; i++) {
        for (j = i + 1; j < MAX_WORDS && strcmp(words[i].word, words[j].word) == 0; j++) {
            words[i].count += words[j].count;
            words[j].count = 0;
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    readWords(file, words);
    fclose(file);

    countWords(words);
    printWords(words);

    return 0;
}