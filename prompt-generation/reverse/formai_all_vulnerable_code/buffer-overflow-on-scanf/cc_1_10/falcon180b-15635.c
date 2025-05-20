//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE* file, WordFrequency words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    char* token;
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void countFrequencies(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void printFrequencies(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE* file;
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    WordFrequency words[MAX_NUM_WORDS];
    int numWords = 0;
    readWords(file, words, MAX_NUM_WORDS);
    countFrequencies(words, numWords);
    printFrequencies(words, numWords);
    fclose(file);
    return 0;
}