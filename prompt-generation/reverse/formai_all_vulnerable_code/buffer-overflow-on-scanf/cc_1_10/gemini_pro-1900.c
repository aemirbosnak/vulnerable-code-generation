//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100

// Function to check if a word is in the dictionary
int is_in_dictionary(char* word, char** dictionary, int dictionary_size) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to suggest corrections for a misspelled word
char** suggest_corrections(char* word, char** dictionary, int dictionary_size) {
    // Allocate memory for the array of suggestions
    char** suggestions = malloc(MAX_DICTIONARY_SIZE * sizeof(char*));

    // Initialize the number of suggestions to 0
    int num_suggestions = 0;

    // Iterate over the dictionary and find words that are similar to the misspelled word
    for (int i = 0; i < dictionary_size; i++) {
        // Check if the word in the dictionary is similar to the misspelled word
        if (strcmp(word, dictionary[i]) != 0) {
            // Check if the misspelled word is one character away from the word in the dictionary
            if (strcmp(word, dictionary[i]) == 1) {
                // Add the word in the dictionary to the array of suggestions
                suggestions[num_suggestions++] = dictionary[i];
            }
        }
    }

    // Return the array of suggestions
    return suggestions;
}

// Function to print the suggestions for a misspelled word
void print_suggestions(char** suggestions, int num_suggestions) {
    // Print the suggestions
    printf("Did you mean:\n");
    for (int i = 0; i < num_suggestions; i++) {
        printf("%s\n", suggestions[i]);
    }
}

// Main function
int main() {
    // Create a dictionary of words
    char* dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    int dictionary_size = sizeof(dictionary) / sizeof(dictionary[0]);

    // Get the misspelled word from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a misspelled word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    if (is_in_dictionary(word, dictionary, dictionary_size)) {
        printf("The word is spelled correctly.\n");
    } else {
        // Suggest corrections for the misspelled word
        char** suggestions = suggest_corrections(word, dictionary, dictionary_size);
        int num_suggestions = sizeof(suggestions) / sizeof(suggestions[0]);

        // Print the suggestions
        print_suggestions(suggestions, num_suggestions);
    }

    return 0;
}