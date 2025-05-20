//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LIST_SIZE 1000

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to read a dictionary file and store words in an array
int loadDictionary(const char *filename, char dictionary[][MAX_WORD_LEN]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < MAX_LIST_SIZE) {
        toLowerCase(dictionary[count]); // Convert to lowercase
        count++;
    }
    fclose(file);
    return count;  // Return the number of words loaded
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char *word, char dictionary[][MAX_WORD_LEN], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to spell check a given text
void spellCheckText(const char *text, char dictionary[][MAX_WORD_LEN], int dictSize) {
    char word[MAX_WORD_LEN];
    int index = 0;

    for (int i = 0; i <= strlen(text); i++) {
        char currentChar = text[i];

        // If character is a letter, keep adding to the current word
        if (isalpha(currentChar)) {
            word[index++] = currentChar;
        } else {
            // If we've encountered a non-letter and if we have a word recorded
            if (index > 0) {
                word[index] = '\0'; // Null-terminate the current word
                if (!isWordInDictionary(word, dictionary, dictSize)) {
                    printf("Misspelled word: %s\n", word);
                }
                index = 0; // Reset index for the next word
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_LIST_SIZE][MAX_WORD_LEN];
    int dictSize = loadDictionary(argv[1], dictionary);
    if (dictSize < 0) {
        return EXIT_FAILURE; // Dictionary loading failed
    }
    
    FILE *textFile = fopen(argv[2], "r");
    if (!textFile) {
        fprintf(stderr, "Could not open text file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Buffer to hold lines of text
    char line[1024];
    while (fgets(line, sizeof(line), textFile)) {
        spellCheckText(line, dictionary, dictSize);
    }

    fclose(textFile);
    return EXIT_SUCCESS;
}