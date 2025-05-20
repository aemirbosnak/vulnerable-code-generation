//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
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

void readWords(FILE *fp, WordFrequency *words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int wordIndex = 0;
        while (wordIndex < MAX_WORDS && strcmp(words[wordIndex].word, word)!= 0) {
            wordIndex++;
        }
        if (wordIndex == MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }
        words[wordIndex].count++;
    }
}

void printWordFrequencies(WordFrequency *words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    WordFrequency words[MAX_WORDS];
    readWords(fp, words);
    fclose(fp);
    printWordFrequencies(words);
    return 0;
}