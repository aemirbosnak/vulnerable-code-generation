//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE *file, WordFrequency *words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            strcpy(words->word, word);
            words->count = 1;
            words++;
        }
    }
}

void printWords(const WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(file, words);
    fclose(file);

    printWords(words, numWords);

    return 0;
}