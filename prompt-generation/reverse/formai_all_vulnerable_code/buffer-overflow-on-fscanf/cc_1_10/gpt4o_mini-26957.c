//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function to load dictionary words into an array
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open %s for reading.\n", filename);
        return -1;
    }

    int word_count = 0;
    while (fscanf(file, "%s", dictionary[word_count]) != EOF && word_count < DICTIONARY_SIZE) {
        word_count++;
    }
    fclose(file);
    return word_count;
}

// Function to check if a word is in the dictionary
int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is correct
        }
    }
    return 0; // Word is incorrect
}

// Function to suggest words based on common spelling mistakes
void suggest_corrections(const char *misspelled_word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    printf("Suggestions for '%s':\n", misspelled_word);
    for (int i = 0; i < dict_size; i++) {
        // Simple hint: Print words that are close in length
        if (abs(strlen(misspelled_word) - strlen(dictionary[i])) <= 2) {
            printf("- %s\n", dictionary[i]);
        }
    }
}

// The main spell-checking function
void spell_checker(const char *input_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Could not open %s for reading.\n", input_filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word) != EOF) {
        // Check each word against the dictionary
        if (!check_word(word, dictionary, dict_size)) {
            printf("Misspelled word: '%s'.\n", word);
            suggest_corrections(word, dictionary, dict_size);
        }
    }

    fclose(input_file);
}

int main(int argc, char *argv[]) {
    const char *dictionary_filename = "dictionary.txt";
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(dictionary_filename, dictionary);

    if (dict_size < 0) {
        return EXIT_FAILURE; // Exit if dictionary loading failed
    }

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE; // Exit if no input file provided
    }

    printf("Welcome to the Spell Checker! 🌟\n");
    printf("We are grateful to help you ensure your writing is error-free!\n");

    spell_checker(argv[1], dictionary, dict_size);

    printf("Thank you for using the Spell Checker! Have a wonderful day! 😊\n");
    return EXIT_SUCCESS;
}