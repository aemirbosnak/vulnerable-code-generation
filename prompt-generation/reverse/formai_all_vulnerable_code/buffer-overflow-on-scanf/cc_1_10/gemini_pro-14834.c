//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty alien language dictionary
char *alien_dict[] = {
    "Gloop", "Shlob", "Flarp", "Blorf", "Zorp",
    "Wibble", "Wobble", "Zoop", "Zoopity", "Zop"
};

// Our equally trusty English dictionary
char *english_dict[] = {
    "Hello", "Goodbye", "Thank you", "You're welcome", "Please",
    "Excuse me", "I'm sorry", "No problem", "Yes", "No"
};

// Function to translate from alien to English
char *alien_to_english(char *alien_word) {
    // Search for the alien word in our dictionary
    for (int i = 0; i < sizeof(alien_dict) / sizeof(char *); i++) {
        if (strcmp(alien_word, alien_dict[i]) == 0) {
            // We found a match! Return the corresponding English word.
            return english_dict[i];
        }
    }

    // We didn't find a match. Return an error message.
    return "Sorry, I don't know that word.";
}

// Function to translate from English to alien
char *english_to_alien(char *english_word) {
    // Search for the English word in our dictionary
    for (int i = 0; i < sizeof(english_dict) / sizeof(char *); i++) {
        if (strcmp(english_word, english_dict[i]) == 0) {
            // We found a match! Return the corresponding alien word.
            return alien_dict[i];
        }
    }

    // We didn't find a match. Return an error message.
    return "Sorry, I don't know that word.";
}

int main() {
    // Get the input from the user
    char input[100];
    printf("Enter an alien word or an English word to translate: ");
    scanf("%s", input);

    // Determine the language of the input
    int is_alien = 0;
    for (int i = 0; i < sizeof(alien_dict) / sizeof(char *); i++) {
        if (strcmp(input, alien_dict[i]) == 0) {
            is_alien = 1;
            break;
        }
    }

    // Translate the input accordingly
    char *translation;
    if (is_alien) {
        translation = alien_to_english(input);
    } else {
        translation = english_to_alien(input);
    }

    // Print the translation
    printf("Translation: %s\n", translation);

    return 0;
}