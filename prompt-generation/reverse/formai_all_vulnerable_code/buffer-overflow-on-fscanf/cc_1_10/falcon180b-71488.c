//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character

        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0'; // Remove non-alphabetic characters
            }
        }

        int wordIndex = 0;
        while (wordFrequencies[wordIndex].word[0]!= '\0' && strcmp(word, wordFrequencies[wordIndex].word)!= 0) {
            wordIndex++;
        }

        if (wordFrequencies[wordIndex].word[0] == '\0') {
            strcpy(wordFrequencies[wordIndex].word, word);
            wordFrequencies[wordIndex].count = 1;
        } else {
            wordFrequencies[wordIndex].count++;
        }
    }

    fclose(file);
}

void writeWordFrequencies(WordFrequency* wordFrequencies) {
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (wordFrequencies[i].word[0]!= '\0') {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORD_COUNT];
    readWords(argv[1], wordFrequencies);
    writeWordFrequencies(wordFrequencies);

    return 0;
}