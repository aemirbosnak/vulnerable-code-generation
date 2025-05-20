//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// Function to convert a string to lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower((unsigned char)word[i]);
    }
}

// Function to load the dictionary into memory
int load_dictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open dictionary file %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) == 1 && count < MAX_DICTIONARY_SIZE) {
        to_lowercase(dictionary[count]); // Normalize to lowercase
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found in dictionary
        }
    }
    return 0; // Word not found
}

// Function to spell check a text file
void spell_check(const char *input_filename, const char *output_filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file || !output_file) {
        fprintf(stderr, "Error: Unable to open input or output file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word) == 1) {
        // Remove punctuation and normalize
        char cleaned_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha((unsigned char)word[i]) || word[i] == '\'') {
                cleaned_word[j++] = word[i];
            }
        }
        cleaned_word[j] = '\0';
        to_lowercase(cleaned_word);

        // Check spelling
        if (!is_word_in_dictionary(cleaned_word, dictionary, dict_size)) {
            fprintf(output_file, "%s\n", cleaned_word);
        }
    }
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <dictionary_file> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);
    if (dict_size < 0) {
        return EXIT_FAILURE;
    }

    spell_check(argv[2], argv[3], dictionary, dict_size);
    printf("Spell checking complete. Check the output file for misspelled words.\n");

    return EXIT_SUCCESS;
}