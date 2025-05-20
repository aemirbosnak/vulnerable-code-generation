//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function to load words from a file into an array
int loadWords(const char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s", words[count]) != EOF && count < MAX_WORDS) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Word not found
}

// Function to perform spell checking on a text file
void spellCheck(const char *textFilename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dictSize) {
    FILE *file = fopen(textFilename, "r");
    if (!file) {
        perror("Error opening text file");
        return;
    }
    
    char word[MAX_WORD_LENGTH];
    int lineNumber = 1;
    
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from the word for checking
        char cleanWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (isalpha(word[i]) || word[i] == '\'') {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';

        // Check if the word is in the dictionary
        if (!isWordInDictionary(cleanWord, dictionary, dictSize)) {
            printf("Misspelled word: '%s' at line %d\n", cleanWord, lineNumber);
        }
        
        // Track the line number (simple :) - you can enhance this logic
        if (strchr(word, '\n') != NULL) {
            lineNumber++;
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int dictSize = loadWords(argv[1], dictionary);
    
    if (dictSize < 0) {
        return EXIT_FAILURE; // Exit if there was an error loading the dictionary
    }

    spellCheck(argv[2], dictionary, dictSize);

    return EXIT_SUCCESS;
}