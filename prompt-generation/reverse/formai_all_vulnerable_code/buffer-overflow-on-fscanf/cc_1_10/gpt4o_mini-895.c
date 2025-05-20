//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

// Function to load dictionary into memory
int loadDictionary(char *filename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        return -1;
    }
    
    int wordCount = 0;
    while (fscanf(file, "%s", dictionary[wordCount]) != EOF) {
        wordCount++;
    }

    fclose(file);
    return wordCount;
}

// Function to check if a word is in the dictionary
int checkWord(char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest similar words (basic implementation)
void suggestWords(char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dictSize) {
    printf("Suggestions for \"%s\":\n", word);
    for (int i = 0; i < dictSize; i++) {
        if (strncmp(word, dictionary[i], strlen(word)) == 0) {
            printf("  - %s\n", dictionary[i]);
        }
    }
}

// Main spell checker function
void spellCheck(char *inputText, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dictSize) {
    char *word;
    char text[MAX_WORD_LENGTH * 100]; // Assuming an ample buffer for text
    strcpy(text, inputText);
    word = strtok(text, " ,.;?!\n");

    while (word != NULL) {
        // Remove punctuation from the word
        char cleanWord[MAX_WORD_LENGTH];
        int length = strlen(word);
        int j = 0;

        for (int i = 0; i < length; i++) {
            if (isalpha(word[i])) {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';

        // Check if the cleaned word is in the dictionary
        if (!checkWord(cleanWord, dictionary, dictSize)) {
            printf("Incorrect word: %s\n", cleanWord);
            suggestWords(cleanWord, dictionary, dictSize);
        }

        // Get the next word
        word = strtok(NULL, " ,.;?!\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_to_check>\n", argv[0]);
        return 1;
    }

    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int dictSize = loadDictionary(argv[1], dictionary);
    if (dictSize == -1) {
        return 1; // Error loading dictionary
    }

    // Load the input text
    char *textToCheck = argv[2];

    // Perform spell checking
    spellCheck(textToCheck, dictionary, dictSize);

    return 0;
}