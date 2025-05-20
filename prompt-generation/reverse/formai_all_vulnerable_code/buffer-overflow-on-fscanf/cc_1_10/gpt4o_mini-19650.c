//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

// Function prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count);
void check_spelling(const char *input_filename, char dictionary[][MAX_WORD_LENGTH], int word_count);
void to_lowercase(char *str);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        return 1;
    }

    const char *dictionary_file = argv[1];
    const char *input_file = argv[2];
    
    char dictionary[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    // Load the dictionary
    load_dictionary(dictionary_file, dictionary, &word_count);
    
    // Check spelling of the input file
    check_spelling(input_file, dictionary, word_count);

    return 0;
}

// Load dictionary from a file
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*word_count]) != EOF) {
        to_lowercase(dictionary[*word_count]);
        (*word_count)++;
        if (*word_count >= MAX_NUM_WORDS) {
            break;  // Avoid overflow
        }
    }

    fclose(file);
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Check if a word is in the dictionary
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;  // Word is found
        }
    }
    return 0; // Word is not found
}

// Check spelling of words in a given input file
void check_spelling(const char *input_filename, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    FILE *file = fopen(input_filename, "r");
    if (!file) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int line_number = 1;

    // Read words from the input file
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from the word
        char clean_word[MAX_WORD_LENGTH];
        int j = 0;

        for (int i = 0; word[i] != '\0'; i++) {
            if (isalnum((unsigned char)word[i])) {
                clean_word[j++] = word[i];
            }
        }
        clean_word[j] = '\0';

        // Check if the cleaned word is in the dictionary
        if (!is_word_in_dictionary(clean_word, dictionary, word_count)) {
            printf("Misspelled word '%s' found on line %d\n", clean_word, line_number);
        }

        // Check for line breaks
        if (strchr(word, '\n')) {
            line_number++;
        }
    }

    fclose(file);
}