//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define INPUT_TEXT_SIZE 10000

// Function to load the dictionary into an array
int loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // The word is found
        }
    }
    return 0; // The word is not found
}

// Function to extract words from text and perform spell check
void spellCheckText(const char *text, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++) {
        // If we encounter a letter, build the word
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            word[wordIndex++] = text[i];
        } else {
            // We hit a non-letter character, finalize the word if there's one
            if (wordIndex > 0) {
                word[wordIndex] = '\0'; // Null-terminate the string
                if (!isWordInDictionary(word, dictionary, dictSize)) {
                    printf("Misspelled Word: %s\n", word);
                }
                wordIndex = 0; // Reset the index for the next word
            }
        }
    }

    // Final check for the last word if text ends with a letter
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        if (!isWordInDictionary(word, dictionary, dictSize)) {
            printf("Misspelled Word: %s\n", word);
        }
    }
}

// Main function to run the spell checker
int main(int argc, char *argv[]) {
    // Check if the right number of arguments are provided
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <input_text>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictSize = loadDictionary(argv[1], dictionary);
    if (dictSize < 0) {
        return 1; // Error loading dictionary
    }

    // Read input text from a file
    FILE *inputFile = fopen(argv[2], "r");
    if (!inputFile) {
        perror("Could not open input text file");
        return 1;
    }

    char text[INPUT_TEXT_SIZE];
    fread(text, sizeof(char), INPUT_TEXT_SIZE, inputFile);
    fclose(inputFile);

    // Perform spell checking
    printf("Starting spell check...\n");
    spellCheckText(text, dictionary, dictSize);
    printf("Spell check completed. \n");

    return 0;
}