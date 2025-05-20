//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE* file, WordFrequency* words, int numWords, int* numWordsRead) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF && *numWordsRead < numWords) {
        strcpy(words[*numWordsRead].word, word);
        (*numWordsRead)++;
    }
}

void countWords(char* text, WordFrequency* words, int numWords) {
    char* token = strtok(text, ",.?!;:\"'");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords - 1].word, token);
            words[numWords - 1].frequency = 1;
            numWords++;
        }
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void printWords(WordFrequency* words, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while (true) {
        int numWordsRead = 0;
        readWords(inputFile, words, MAX_WORDS - numWords, &numWordsRead);
        if (numWordsRead == 0) {
            break;
        }
        numWords += numWordsRead;
    }

    fclose(inputFile);

    printf("Total words: %d\n", numWords);
    printWords(words, numWords);

    return 0;
}