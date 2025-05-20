//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a word is in the dictionary
bool is_word_in_dictionary(const char *word, const char **dictionary, size_t dictionary_size) {
    for (size_t i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }

    return false;
}

// Function to suggest corrections for a misspelled word
char **suggest_corrections(const char *word, const char **dictionary, size_t dictionary_size) {
    // Allocate memory for the array of suggested corrections
    char **corrections = malloc(sizeof(char *) * 10);

    // Initialize the number of suggested corrections to 0
    size_t num_corrections = 0;

    // Iterate over the words in the dictionary
    for (size_t i = 0; i < dictionary_size; i++) {
        // Check if the word in the dictionary is within one edit distance of the misspelled word
        if (strcmp(word, dictionary[i]) == 0) {
            // Add the word to the array of suggested corrections
            corrections[num_corrections++] = strdup(dictionary[i]);
        }
    }

    // Return the array of suggested corrections
    return corrections;
}

// Function to print the suggested corrections for a misspelled word
void print_corrections(const char **corrections, size_t num_corrections) {
    // Print the suggested corrections
    for (size_t i = 0; i < num_corrections; i++) {
        printf("%s\n", corrections[i]);
    }

    // Free the memory allocated for the array of suggested corrections
    for (size_t i = 0; i < num_corrections; i++) {
        free(corrections[i]);
    }
    free(corrections);
}

// Main function
int main() {
    // Define the dictionary
    const char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    size_t dictionary_size = sizeof(dictionary) / sizeof(dictionary[0]);

    // Get the misspelled word from the user
    char word[100];
    printf("Enter a misspelled word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    if (is_word_in_dictionary(word, dictionary, dictionary_size)) {
        printf("The word is spelled correctly.\n");
    } else {
        // Suggest corrections for the misspelled word
        char **corrections = suggest_corrections(word, dictionary, dictionary_size);

        // Print the suggested corrections
        printf("Suggested corrections:\n");
        print_corrections(corrections, 10);
    }

    return 0;
}