//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_ENTRIES 10000

// Function declarations
void to_lower_case(char *word);
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void check_spelling(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_DICT_ENTRIES][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);

    if (dict_size < 0) {
        fprintf(stderr, "Error loading dictionary.\n");
        return EXIT_FAILURE;
    }

    check_spelling(argv[2], dictionary, dict_size);
    return EXIT_SUCCESS;
}

// Function to occur each word to lower case for a standardized comparison
void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower((unsigned char) word[i]);
    }
}

// Function to load a dictionary from a file
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) == 1) {
        to_lower_case(dictionary[count]);
        count++;
        if (count >= MAX_DICT_ENTRIES) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to check if a given word resides within the dictionary
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to check the spelling of words in a text file
void check_spelling(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(text_filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file %s\n", text_filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    int line_number = 1;

    while (fscanf(file, "%s", word) == 1) {
        // Check for line breaks (simulating words across lines)
        if (strcmp(word, "\n") == 0) {
            line_number++;
            continue;
        }

        // Handle only alphabetic characters for simplicity
        char clean_word[MAX_WORD_LENGTH] = {0};
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha((unsigned char) word[i]) || word[i] == '\'') {
                clean_word[j++] = word[i];
            }
        }
        clean_word[j] = '\0';
        to_lower_case(clean_word);

        // Check for spelling
        if (!is_word_in_dictionary(clean_word, dictionary, dict_size)) {
            printf("Misspelled word '%s' found on line %d\n", clean_word, line_number);
        }
    }

    fclose(file);
}