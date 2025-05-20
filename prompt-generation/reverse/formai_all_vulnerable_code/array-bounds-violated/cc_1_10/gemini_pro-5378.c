//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_WORDS 10000

// Structure to represent a word in the dictionary
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
} DictionaryWord;

// Array to store the dictionary words
DictionaryWord dictionary[MAX_DICTIONARY_WORDS];

// Number of words in the dictionary
int num_dictionary_words = 0;

// Function to load the dictionary from a file
void load_dictionary(const char *filename) {
    // Open the dictionary file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file: %s\n", filename);
        exit(1);
    }

    // Read each word from the dictionary file
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove the newline character from the word
        line[strlen(line) - 1] = '\0';

        // Convert the word to lowercase
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Add the word to the dictionary
        strcpy(dictionary[num_dictionary_words].word, line);
        num_dictionary_words++;
    }

    // Close the dictionary file
    fclose(fp);
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word) {
    // Convert the word to lowercase
    char lower_word[MAX_WORD_LENGTH + 1];
    strcpy(lower_word, word);
    for (int i = 0; lower_word[i] != '\0'; i++) {
        lower_word[i] = tolower(lower_word[i]);
    }

    // Search for the word in the dictionary
    for (int i = 0; i < num_dictionary_words; i++) {
        if (strcmp(lower_word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    // The word is not in the dictionary
    return 0;
}

// Function to check the spelling of a word
int check_spelling(const char *word) {
    // Check if the word is in the dictionary
    if (is_word_in_dictionary(word)) {
        return 1;
    }

    // The word is not in the dictionary, so it is misspelled
    return 0;
}

// Function to get a list of suggested spellings for a misspelled word
char **get_suggested_spellings(const char *word, int *num_suggestions) {
    // Allocate memory for the array of suggested spellings
    char **suggested_spellings = malloc(sizeof(char *) * MAX_WORD_LENGTH);

    // Initialize the number of suggested spellings to 0
    *num_suggestions = 0;

    // Loop through all the words in the dictionary
    for (int i = 0; i < num_dictionary_words; i++) {
        // Check if the misspelled word is similar to the current word in the dictionary
        if (strcmp(word, dictionary[i].word) == 1) {
            // Add the current word to the array of suggested spellings
            suggested_spellings[*num_suggestions] = malloc(sizeof(char) * (strlen(dictionary[i].word) + 1));
            strcpy(suggested_spellings[*num_suggestions], dictionary[i].word);
            (*num_suggestions)++;
        }
    }

    // Return the array of suggested spellings
    return suggested_spellings;
}

// Function to print the suggested spellings for a misspelled word
void print_suggested_spellings(const char *word, char **suggested_spellings, int num_suggestions) {
    // Print the misspelled word
    printf("Misspelled word: %s\n", word);

    // Print the suggested spellings
    if (num_suggestions == 0) {
        printf("No suggested spellings found.\n");
    } else {
        printf("Suggested spellings:\n");
        for (int i = 0; i < num_suggestions; i++) {
            printf("    %s\n", suggested_spellings[i]);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Load the dictionary from the file
    load_dictionary("dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH + 1];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_spelled_correctly = check_spelling(word);

    // Print the result
    if (is_spelled_correctly) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        // Get the suggested spellings for the misspelled word
        int num_suggestions;
        char **suggested_spellings = get_suggested_spellings(word, &num_suggestions);

        // Print the suggested spellings
        print_suggested_spellings(word, suggested_spellings, num_suggestions);

        // Free the memory allocated for the suggested spellings
        for (int i = 0; i < num_suggestions; i++) {
            free(suggested_spellings[i]);
        }
        free(suggested_spellings);
    }

    return 0;
}