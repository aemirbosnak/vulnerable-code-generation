//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(FILE* file, WordFrequency* words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
    }
}

void writeWords(FILE* file, WordFrequency* words) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < MAX_WORDS; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    readWords(inputFile, words);
    writeWords(outputFile, words);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}