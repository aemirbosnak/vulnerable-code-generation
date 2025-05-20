//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define WORD_MAX_LENGTH 100

typedef struct {
    char word[WORD_MAX_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(char *filename, WordFrequency words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char word[WORD_MAX_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Warning: maximum number of words reached\n");
        }
    }
    fclose(file);
}

void writeWords(const WordFrequency words[], int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    readWords(filename, words);
    writeWords(words, numWords);
    return 0;
}