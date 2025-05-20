//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Create a struct to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} Word;

// Create a dictionary of words
Word dictionary[MAX_WORDS];
int numWords = 0;

// Function to read the dictionary from a file
void readDictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", dictionary[numWords].word) != EOF) {
        dictionary[numWords].frequency = 0;
        numWords++;
    }

    fclose(fp);
}

// Function to check if a word is in the dictionary
int isWordInDictionary(char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to spell check a word
void spellCheckWord(char *word) {
    if (isWordInDictionary(word)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }
}

// Function to spell check a file
void spellCheckFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        spellCheckWord(word);
    }

    fclose(fp);
}

int main() {
    // Read the dictionary from a file
    readDictionary("dictionary.txt");

    // Spell check a word
    spellCheckWord("hello");

    // Spell check a file
    spellCheckFile("test.txt");

    return 0;
}