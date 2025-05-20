//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

void readWords(FILE* inputFile, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }
}

void countWordFrequencies(char words[MAX_WORDS][MAX_WORD_LENGTH], int wordCounts[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        wordCounts[i] = 0;
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i], "")!= 0) {
            wordCounts[i]++;
        }
    }
}

void printWordFrequencies(WordFrequency wordFrequencies[MAX_WORDS]) {
    qsort(wordFrequencies, MAX_WORDS, sizeof(WordFrequency), compareStrings);

    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    readWords(inputFile, words);

    int wordCounts[MAX_WORDS];
    countWordFrequencies(words, wordCounts);

    WordFrequency wordFrequencies[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        strcpy(wordFrequencies[i].word, words[i]);
        wordFrequencies[i].count = wordCounts[i];
    }

    printWordFrequencies(wordFrequencies);

    fclose(inputFile);
    return 0;
}