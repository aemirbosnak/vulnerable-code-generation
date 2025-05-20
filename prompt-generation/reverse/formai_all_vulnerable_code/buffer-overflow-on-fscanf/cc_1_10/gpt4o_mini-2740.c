//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Function prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size);
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void to_lowercase(char *str);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = 0;
    char input_word[MAX_WORD_LENGTH];

    // Load the dictionary from a file
    load_dictionary("dictionary.txt", dictionary, &dict_size);

    printf("Welcome to the Spell Checker!\n");
    printf("Please enter words to check ('exit' to quit):\n");

    while (1) {
        printf("> ");
        scanf("%s", input_word);

        // Handle exit command
        if (strcmp(input_word, "exit") == 0) {
            printf("Exiting Spell Checker. Have a great day!\n");
            break;
        }

        // Convert input to lowercase for uniform comparison
        to_lowercase(input_word);

        // Check for spelling
        if (check_word(input_word, dictionary, dict_size)) {
            printf("'%s' is spelled correctly.\n", input_word);
        } else {
            printf("'%s' is spelled incorrectly.\n", input_word);
        }
    }

    return 0;
}

// Function to load the dictionary from a file
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF) {
        (*dict_size)++;
        if (*dict_size >= DICTIONARY_SIZE) break;
    }

    fclose(file);
}

// Function to check if a word exists in the dictionary
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}