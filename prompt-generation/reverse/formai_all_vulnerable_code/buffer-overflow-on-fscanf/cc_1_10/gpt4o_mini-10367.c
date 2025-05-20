//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define MAX_INPUT_LENGTH 1000

// Structure to hold the dictionary words
typedef struct {
    char word[MAX_WORD_LENGTH];
} Dictionary;

// Function to load the dictionary from a file
int load_dictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening dictionary file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s", dict[count].word) != EOF && count < DICTIONARY_SIZE) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(Dictionary *dict, int dict_size, const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest similar words (only first letter replacement for simplicity)
void suggest_words(Dictionary *dict, int dict_size, const char *word) {
    printf("Suggested corrections for '%s':\n", word);
    for (int i = 0; i < dict_size; i++) {
        if (strncmp(dict[i].word, word + 1, strlen(word) - 1) == 0 && 
            dict[i].word[0] != word[0]) {
            printf("- %s\n", dict[i].word);
        }
    }
}

// Main function to perform spell checking
int main() {
    Dictionary dict[DICTIONARY_SIZE];
    const char *dictionary_file = "dictionary.txt"; // Your dictionary file path
    char input[MAX_INPUT_LENGTH];

    // Load the dictionary
    int dict_size = load_dictionary(dict, dictionary_file);
    if (dict_size == 0) {
        return 1; // Exit if dictionary can't be loaded
    }

    printf("Enter a sentence to check for spelling errors:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    char *word = strtok(input, " ");
    while (word != NULL) {
        // Strip punctuation
        char *end = word + strlen(word) - 1;
        while (end > word && ispunct(*end)) {
            *end-- = '\0';
        }

        // Check if the word is in the dictionary
        if (!is_word_in_dictionary(dict, dict_size, word)) {
            printf("Spelling mistake found: '%s'\n", word);
            suggest_words(dict, dict_size, word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}