//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function prototypes
void load_dictionary(char *filename, char dict[][MAX_WORD_LENGTH], int *word_count);
int check_spelling(char *word, char dict[][MAX_WORD_LENGTH], int word_count);
void to_lowercase(char *str);
void get_input_text(char *input_text, size_t size);

int main() {
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH]; // Dictionary array for words
    int word_count = 0; // Total number of words loaded from dictionary
    char input_text[1000]; // Input text where we will check spelling
    char *word; // Pointer to traverse words in the input text

    // Load the dictionary
    load_dictionary("dictionary.txt", dictionary, &word_count);

    // Get input text to check for spelling
    printf("Please enter the text to check for spelling:\n");
    get_input_text(input_text, sizeof(input_text));

    // Tokenize the input text based on spaces and punctuation
    word = strtok(input_text, " ,.-!?\n");
    while (word != NULL) {
        // Convert word to lowercase for consistent checking
        char temp_word[MAX_WORD_LENGTH];
        strcpy(temp_word, word);
        to_lowercase(temp_word);

        // Check spelling
        if (!check_spelling(temp_word, dictionary, word_count)) {
            printf("Misspelled word: '%s'\n", word);
        }

        // Get the next word
        word = strtok(NULL, " ,.-!?\n");
    }

    return 0; // Normal termination
}

// Load dictionary from a file
void load_dictionary(char *filename, char dict[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dict[*word_count]) != EOF && *word_count < MAX_WORDS) {
        (*word_count)++;
    }
    fclose(file);
}

// Check if a word exists in the dictionary
int check_spelling(char *word, char dict[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1; // Word is found in dictionary
        }
    }
    return 0; // Word is not found in dictionary
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Get input text from user
void get_input_text(char *input_text, size_t size) {
    if (fgets(input_text, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input text.\n");
        exit(EXIT_FAILURE);
    }
}