//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
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

WordFrequency wordList[MAX_WORDS];
int totalWords = 0;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void addWord(const char *word) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return;
        }
    }
    if (totalWords < MAX_WORDS) {
        strncpy(wordList[totalWords].word, word, MAX_WORD_LENGTH);
        wordList[totalWords].count = 1;
        totalWords++;
    } else {
        fprintf(stderr, "Maximum word limit reached! Cannot add more words.\n");
    }
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        
        // Remove punctuation from the word
        char cleanWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';
        
        if (j > 0) {
            addWord(cleanWord);
        }
    }
    fclose(file);
}

void printWordFrequencies() {
    printf("Word Frequency Count:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%-15s %d\n", wordList[i].word, wordList[i].count);
    }
    printf("--------------------------------\n");
}

void sortWordsByFrequency() {
    for (int i = 0; i < totalWords - 1; i++) {
        for (int j = 0; j < totalWords - i - 1; j++) {
            if (wordList[j].count < wordList[j + 1].count) {
                WordFrequency temp = wordList[j];
                wordList[j] = wordList[j + 1];
                wordList[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processFile(argv[1]);
    sortWordsByFrequency();
    printWordFrequencies();

    return EXIT_SUCCESS;
}