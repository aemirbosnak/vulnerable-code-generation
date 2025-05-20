//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

bool isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void splitWord(const char *line, Word *words, int *numWords) {
    int index = 0;
    int wordIndex = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        if (isDelimiter(line[i])) {
            words[wordIndex].str[index] = '\0';
            ++wordIndex;
            if (wordIndex >= MAX_WORDS) {
                fprintf(stderr, "Max number of words reached\n");
                exit(EXIT_FAILURE);
            }
            index = 0;
        } else {
            words[wordIndex].str[index++] = line[i];
        }
    }
    words[wordIndex].str[index] = '\0';
    ++*numWords;
}

void incrementWordCount(Word *words, int numWords, const char *word) {
    for (int i = 0; i < numWords; ++i) {
        if (strcmp(words[i].str, word) == 0) {
            ++words[i].count;
            return;
        }
    }
    for (int i = 0; i < numWords; ++i) {
        if (words[i].count == 0) {
            strcpy(words[i].str, word);
            words[i].count = 1;
            return;
        }
    }
}

int main() {
    char line[1024];
    Word words[MAX_WORDS];
    int numWords = 0;
    while (fgets(line, sizeof(line), stdin) != NULL) {
        toLowerCase(line);
        splitWord(line, words, &numWords);
        for (int i = 0; i < numWords; ++i) {
            incrementWordCount(words, numWords, words[i].str);
        }
    }
    for (int i = 0; i < numWords; ++i) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].str, words[i].count);
        }
    }
    return EXIT_SUCCESS;
}