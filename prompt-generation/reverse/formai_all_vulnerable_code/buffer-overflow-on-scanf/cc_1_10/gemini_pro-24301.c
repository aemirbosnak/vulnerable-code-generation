//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

// Define the alien language dictionary
const char *alien_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Define the human language dictionary
const char *human_dictionary[] = {
    "apple", "banana", "cherry", "dog", "elephant", "fish",
    "grape", "house", "ice cream", "juice", "kiwi", "lemon",
    "mango", "nut", "orange", "pear", "pineapple", "queen",
    "rabbit", "strawberry", "tiger", "umbrella", "violin",
    "watermelon", "x-ray", "yacht", "zebra"
};

// Translate a word from alien language to human language
char *translate_alien_to_human(char *alien_word) {
    // Allocate memory for the translated word
    char *human_word = malloc(MAX_WORD_LENGTH * sizeof(char));

    // Iterate over the characters in the alien word
    int i = 0;
    while (alien_word[i] != '\0') {
        // Find the index of the alien character in the alien dictionary
        int alien_index = 0;
        while (strcmp(alien_dictionary[alien_index], &alien_word[i]) != 0) {
            alien_index++;
        }

        // Get the human language equivalent of the alien character
        char human_character = human_dictionary[alien_index][0];

        // Append the human character to the translated word
        human_word[i] = human_character;

        // Increment the index
        i++;
    }

    // Add the null terminator to the translated word
    human_word[i] = '\0';

    // Return the translated word
    return human_word;
}

// Translate a word from human language to alien language
char *translate_human_to_alien(char *human_word) {
    // Allocate memory for the translated word
    char *alien_word = malloc(MAX_WORD_LENGTH * sizeof(char));

    // Iterate over the characters in the human word
    int i = 0;
    while (human_word[i] != '\0') {
        // Find the index of the human character in the human dictionary
        int human_index = 0;
        while (human_dictionary[human_index][0] != human_word[i]) {
            human_index++;
        }

        // Get the alien language equivalent of the human character
        char alien_character = alien_dictionary[human_index][0];

        // Append the alien character to the translated word
        alien_word[i] = alien_character;

        // Increment the index
        i++;
    }

    // Add the null terminator to the translated word
    alien_word[i] = '\0';

    // Return the translated word
    return alien_word;
}

// Main function
int main() {
    // Get the word to be translated
    char word[MAX_WORD_LENGTH];
    printf("Enter the word to be translated: ");
    scanf("%s", word);

    // Translate the word from alien language to human language
    char *human_word = translate_alien_to_human(word);

    // Print the translated word
    printf("The human language equivalent of '%s' is '%s'\n", word, human_word);

    // Free the memory allocated for the translated word
    free(human_word);

    // Translate the word from human language to alien language
    char *alien_word = translate_human_to_alien(word);

    // Print the translated word
    printf("The alien language equivalent of '%s' is '%s'\n", word, alien_word);

    // Free the memory allocated for the translated word
    free(alien_word);

    return 0;
}