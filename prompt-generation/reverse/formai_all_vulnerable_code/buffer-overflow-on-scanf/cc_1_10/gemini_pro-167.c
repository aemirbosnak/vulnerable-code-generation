//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Dictionary of valid words
char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "horse", "igloo", "juice"};

// Function to check if a word is in the dictionary
int is_valid_word(char *word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is misspelled
int is_misspelled(char *word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (strcmp(word, dictionary[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

// Function to correct a misspelled word
char *correct_word(char *word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (strcmp(word, dictionary[i]) == 1) {
            return dictionary[i];
        }
    }
    return NULL;
}

// Function to get a word from the user
char *get_word(void) {
    char *word = malloc(100);
    scanf("%s", word);
    return word;
}

// Main function
int main(void) {
    char *word;

    // Get a word from the user
    word = get_word();

    // Check if the word is valid
    if (is_valid_word(word)) {
        printf("%s is a valid word.\n", word);
    } else {
        // Check if the word is misspelled
        if (is_misspelled(word)) {
            // Correct the misspelled word
            char *corrected_word = correct_word(word);
            printf("%s is a misspelled word. The correct spelling is %s.\n", word, corrected_word);
        } else {
            // The word is not in the dictionary
            printf("%s is not a valid word.\n", word);
        }
    }

    // Free the allocated memory
    free(word);

    return 0;
}