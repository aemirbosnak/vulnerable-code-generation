//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (*numWords >= MAX_WORDS) {
            break;
        }
        WordFrequency newWord = {word, 1};
        words[*numWords] = newWord;
        (*numWords)++;
    }
    fclose(file);
    qsort(words, *numWords, sizeof(WordFrequency), compareWords);
}

void writeFrequencies(const char *filename, WordFrequency *words, int numWords) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }
    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    readWords(inputFilename, words, &numWords);
    writeFrequencies(outputFilename, words, numWords);
    return 0;
}