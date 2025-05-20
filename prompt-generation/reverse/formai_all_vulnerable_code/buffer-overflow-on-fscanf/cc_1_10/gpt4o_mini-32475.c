//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int findWord(char *word, WordCount *wordCounts, int wordCountSize) {
    for(int i = 0; i < wordCountSize; i++) {
        if(strcmp(wordCounts[i].word, word) == 0) {
            return i; // Return the index of the matching word
        }
    }
    return -1; // Word not found
}

void incrementWordCount(char *word, WordCount *wordCounts, int *wordCountSize) {
    int index = findWord(word, wordCounts, *wordCountSize);
    if(index != -1) {
        wordCounts[index].count++;
    } else {
        strcpy(wordCounts[*wordCountSize].word, word);
        wordCounts[*wordCountSize].count = 1;
        (*wordCountSize)++;
    }
}

void printWordCounts(WordCount *wordCounts, int wordCountSize) {
    printf("\nWord Frequency Count:\n");
    printf("----------------------\n");
    for(int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int isAlphanumeric(char c) {
    return isalnum((unsigned char)c) || c == '\'';
}

void extractWordsFromFile(FILE *file, WordCount *wordCounts, int *wordCountSize) {
    char buffer[MAX_WORD_LENGTH];
    while(fscanf(file, "%s", buffer) != EOF) {
        char word[MAX_WORD_LENGTH] = "";
        int index = 0;

        for(int j = 0; buffer[j] != '\0'; j++) {
            if(isAlphanumeric(buffer[j])) {
                word[index++] = buffer[j]; // Keep alphanumeric characters
            } else if(index > 0) {
                word[index] = '\0'; // Terminate the word
                toLowerCase(word);
                incrementWordCount(word, wordCounts, wordCountSize);
                index = 0; // Reset for the next word
            }
        }

        if(index > 0) { // If there's any remaining characters in the buffer
            word[index] = '\0';
            toLowerCase(word);
            incrementWordCount(word, wordCounts, wordCountSize);
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordCount wordCounts[MAX_WORDS];
    int wordCountSize = 0;

    extractWordsFromFile(file, wordCounts, &wordCountSize);
    fclose(file);

    printWordCounts(wordCounts, wordCountSize);

    return 0;
}