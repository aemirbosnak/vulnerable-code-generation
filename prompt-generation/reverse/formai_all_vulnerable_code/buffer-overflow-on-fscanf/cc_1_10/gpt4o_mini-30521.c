//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of words and size of the word
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Structure to hold words and their counts
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void load_dictionary(const char *filename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int *dict_size);
int is_word_in_dictionary(const char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_size);
void spell_check_file(const char *filename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_size);
void to_lowercase(char *str);

int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int dict_size = 0;

    // Load the dictionary
    load_dictionary("dictionary.txt", dictionary, &dict_size);

    // Check spelling in the provided text file
    spell_check_file("text_to_check.txt", dictionary, dict_size);

    return 0;
}

// Load dictionary words from a file
void load_dictionary(const char *filename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF) {
        to_lowercase(dictionary[*dict_size]); // Convert to lowercase for consistency
        (*dict_size)++;
        if (*dict_size >= MAX_WORDS) {
            break; // Prevent exceeding array size
        }
    }

    fclose(file);
}

// Convert string to lowercase
void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Check if a word is in the dictionary
int is_word_in_dictionary(const char *word, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Spell check a text file
void spell_check_file(const char *filename, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    printf("Spell Checking: %s\n", filename);
    printf("-----------------------------------\n");

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word); // Convert to lowercase for checking

        // Remove punctuation from the word
        for (int i = strlen(word) - 1; i >= 0; i--) {
            if (ispunct(word[i])) {
                word[i] = '\0';
            } else {
                break;
            }
        }

        // Check if the word is in the dictionary
        if (!is_word_in_dictionary(word, dictionary, dict_size)) {
            printf("Misspelled: %s\n", word);
        }
    }

    fclose(file);
}