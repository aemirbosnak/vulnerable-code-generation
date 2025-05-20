//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: expert-level
// SpellChecker.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100

// Structure to represent a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to read words from a file and store them in an array
int readWords(char *filePath, Word *words, int maxWords) {
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return 1;
    }

    int i = 0;
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL && i < maxWords) {
        // Remove newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Convert the word to lowercase
        for (int j = 0; j < strlen(line); j++) {
            line[j] = tolower(line[j]);
        }

        // Ignore words that are not alphabetic
        if (!isalpha(line[0])) {
            continue;
        }

        // Store the word and its frequency in the array
        strcpy(words[i].word, line);
        words[i].frequency = 1;
        i++;
    }

    fclose(fp);
    return i;
}

// Function to check if a word is a misspelling
bool isMisspelling(Word *words, int numWords, char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return false;
        }
    }

    return true;
}

// Function to print the misspellings
void printMisspellings(Word *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (isMisspelling(words, numWords, words[i].word)) {
            printf("%s\n", words[i].word);
        }
    }
}

int main(int argc, char **argv) {
    // Check if the file path is provided
    if (argc != 2) {
        printf("Usage: ./spellchecker <file_path>\n");
        return 1;
    }

    // Read the words from the file
    char *filePath = argv[1];
    Word words[MAX_WORDS];
    int numWords = readWords(filePath, words, MAX_WORDS);

    // Print the misspellings
    printMisspellings(words, numWords);

    return 0;
}