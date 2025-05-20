//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *fp, WordFrequency *words, int *wordCount) {
    char word[MAX_WORD_LENGTH];
    char *delimiters = ",.!?;:'\"-()[]{}<>";
    int wordLength = 0;
    int delimiterIndex = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (wordLength >= MAX_WORD_LENGTH) {
            printf("Error: word too long\n");
            exit(1);
        }
        for (int i = 0; i < strlen(word); i++) {
            if (!isalnum(word[i])) {
                word[i] = '\0';
            }
        }
        for (int i = 0; i < strlen(delimiters); i++) {
            if (delimiters[i] == word[0]) {
                printf("Error: word starts with delimiter\n");
                exit(1);
            }
        }
        strcpy(words[*wordCount].word, word);
        words[*wordCount].count = 1;
        (*wordCount)++;
    }
}

void sortWords(WordFrequency *words, int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (words[i].count < words[j].count) {
                strcpy(words[i].word, words[j].word);
                words[i].count = words[j].count;
                strcpy(words[j].word, words[i].word);
                words[j].count = words[i].count;
            }
        }
    }
}

void printWords(WordFrequency *words, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }
    WordFrequency words[MAX_WORD_COUNT];
    int wordCount = 0;
    readWords(fp, words, &wordCount);
    fclose(fp);
    sortWords(words, wordCount);
    printWords(words, wordCount);
    return 0;
}