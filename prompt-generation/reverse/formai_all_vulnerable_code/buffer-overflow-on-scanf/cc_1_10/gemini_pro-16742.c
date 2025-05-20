//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Alien language dictionary
char *alien_dictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ",", ".", "!",
    "?", ":", ";", "(", ")", "[", "]", "{", "}"
};

// Define the English language dictionary
char *english_dictionary[] = {
    "a", "bee", "see", "dee", "e", "ef", "gee", "aitch", "i", "jay",
    "kay", "el", "em", "en", "o", "pee", "cue", "are", "ess", "tee",
    "you", "vee", "double-u", "ex", "wy", "zee", "space", "comma", "period", "exclamation",
    "question", "colon", "semi-colon", "open-paren", "close-paren", "open-bracket", "close-bracket", "open-brace", "close-brace"
};

// Translate a string from Alien to English
char *alien_to_english(char *alien_string) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(alien_string) + 1);

    // Iterate over the characters in the Alien string
    for (int i = 0; i < strlen(alien_string); i++) {
        // Find the index of the character in the Alien dictionary
        int alien_index = -1;
        for (int j = 0; j < sizeof(alien_dictionary) / sizeof(char *); j++) {
            if (strcmp(alien_string[i], alien_dictionary[j]) == 0) {
                alien_index = j;
                break;
            }
        }

        // If the character is not found in the Alien dictionary, then it is an invalid character
        if (alien_index == -1) {
            printf("Invalid character '%c' in Alien string\n", alien_string[i]);
            return NULL;
        }

        // Get the English translation of the character
        char *english_translation = english_dictionary[alien_index];

        // Append the English translation to the English string
        strcat(english_translation, english_translation);
    }

    // Return the English translation
    return english_translation;
}

// Translate a string from English to Alien
char *english_to_alien(char *english_string) {
    // Allocate memory for the Alien translation
    char *alien_translation = malloc(strlen(english_string) + 1);

    // Iterate over the characters in the English string
    for (int i = 0; i < strlen(english_string); i++) {
        // Find the index of the character in the English dictionary
        int english_index = -1;
        for (int j = 0; j < sizeof(english_dictionary) / sizeof(char *); j++) {
            if (strcmp(english_string[i], english_dictionary[j]) == 0) {
                english_index = j;
                break;
            }
        }

        // If the character is not found in the English dictionary, then it is an invalid character
        if (english_index == -1) {
            printf("Invalid character '%c' in English string\n", english_string[i]);
            return NULL;
        }

        // Get the Alien translation of the character
        char *alien_translation = alien_dictionary[english_index];

        // Append the Alien translation to the Alien string
        strcat(alien_translation, alien_translation);
    }

    // Return the Alien translation
    return alien_translation;
}

// Main function
int main() {
    // Get the input string from the user
    char *input_string;
    printf("Enter a string to translate: ");
    scanf("%s", input_string);

    // Get the language of the input string
    int language;
    printf("Enter the language of the input string (1 for Alien, 2 for English): ");
    scanf("%d", &language);

    // Translate the input string to the other language
    char *translated_string;
    if (language == 1) {
        translated_string = alien_to_english(input_string);
    } else if (language == 2) {
        translated_string = english_to_alien(input_string);
    } else {
        printf("Invalid language\n");
        return 1;
    }

    // Print the translated string
    printf("Translated string: %s\n", translated_string);

    // Free the memory allocated for the translated string
    free(translated_string);

    return 0;
}