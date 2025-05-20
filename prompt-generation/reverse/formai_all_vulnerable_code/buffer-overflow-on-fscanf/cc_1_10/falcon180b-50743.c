//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Too many words in file\n");
            exit(1);
        }

        WordFrequency *currentWord = &words[*numWords];
        strcpy(currentWord->word, word);
        currentWord->frequency = 1;

        (*numWords)++;
    }

    fclose(file);
}

void sortWords(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        WordFrequency *currentWord = &words[i];
        printf("%s: %d\n", currentWord->word, currentWord->frequency);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, &numWords);
    sortWords(words, numWords);
    printWords(words, numWords);

    return 0;
}