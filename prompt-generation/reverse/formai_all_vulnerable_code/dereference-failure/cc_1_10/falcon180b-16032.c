//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
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

void readFile(FILE *file, WordFrequency *wordFrequencies) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalnum(ch)) {
            wordFrequencies[i].word[wordFrequencies[i].count++] = ch;
        } else {
            wordFrequencies[i].word[wordFrequencies[i].count] = '\0';
            i++;
            if (i >= MAX_WORDS) {
                break;
            }
        }
    }
}

void countWords(WordFrequency *wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(wordFrequencies[i].word, wordFrequencies[j].word) == 0) {
                wordFrequencies[i].count += wordFrequencies[j].count;
                wordFrequencies[j].count = 0;
            }
        }
    }
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", argv[1]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(file, wordFrequencies);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].count > 0) {
            numWords++;
        }
    }

    countWords(wordFrequencies, numWords);

    printf("Word frequencies:\n");
    printWordFrequencies(wordFrequencies, numWords);

    fclose(file);
    return 0;
}