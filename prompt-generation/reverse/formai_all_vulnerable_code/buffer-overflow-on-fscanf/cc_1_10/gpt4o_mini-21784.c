//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_SIZE 10000

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to load the dictionary into an array
int loadDictionary(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        return 0;
    }

    int count = 0;
    while (count < MAX_DICT_SIZE && fscanf(file, "%s", dictionary[count]) == 1) {
        toLowercase(dictionary[count]);
        count++;
    }

    fclose(file);
    return count;
}

// Function to check if a word exists in the dictionary
int isWordInDictionary(const char *word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // word found
        }
    }
    return 0; // word not found
}

// Function to process the text input and check for spelling errors
void checkSpelling(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dictSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file: %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation from the word
        char cleanedWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalnum((unsigned char) word[i])) {
                cleanedWord[j++] = word[i];
            }
        }
        cleanedWord[j] = '\0'; // Null-terminate the cleaned word

        toLowercase(cleanedWord); // Convert to lowercase

        if (!isWordInDictionary(cleanedWord, dictionary, dictSize)) {
            printf("Misspelled word: %s\n", cleanedWord);
        }
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH];
    int dictSize = loadDictionary(argv[1], dictionary);
    if (dictSize == 0) {
        return EXIT_FAILURE;
    }

    checkSpelling(argv[2], dictionary, dictSize);

    return EXIT_SUCCESS;
}