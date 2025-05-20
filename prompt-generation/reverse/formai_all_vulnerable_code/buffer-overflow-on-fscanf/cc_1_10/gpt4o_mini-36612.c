//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isAlphabetic(const char c) {
    return isalpha(c) || c == '\''; // Also consider apostrophe in words
}

int addWord(WordFrequency *words, int numWords, const char *newWord) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].count++;
            return numWords; // Return the unchanged count of words
        }
    }
    
    // If the word is not found, we add it
    strcpy(words[numWords].word, newWord);
    words[numWords].count = 1;
    return numWords + 1; // Increment the number of words
}

void printWordFrequencies(const WordFrequency *words, int numWords) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        // Clean up the word (remove punctuations)
        char cleanedWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; buffer[i]; i++) {
            if (isAlphabetic(buffer[i])) {
                cleanedWord[j++] = buffer[i];
            }
        }
        cleanedWord[j] = '\0';

        if (j > 0) { // Only proceed if we have a valid word
            toLowerCase(cleanedWord);
            numWords = addWord(words, numWords, cleanedWord);
            if (numWords >= MAX_WORDS) {
                printf("Warning: Maximum word limit reached, stopping further counts.\n");
                break;
            }
        }
    }

    fclose(file);
    printWordFrequencies(words, numWords);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processFile(argv[1]);
    return EXIT_SUCCESS;
}