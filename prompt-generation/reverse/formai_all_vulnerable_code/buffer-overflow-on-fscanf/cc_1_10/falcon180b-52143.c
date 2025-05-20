//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
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

void readWords(FILE *file, WordFrequency words[], int *numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= *numWords) {
            *numWords += MAX_WORDS;
            WordFrequency *newWords = realloc(words, sizeof(WordFrequency) * *numWords);
            if (newWords == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }
            words = newWords;
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void countWords(WordFrequency words[], int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(file, words, &numWords);
    countWords(words, numWords);

    fclose(file);
    return 0;
}