//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Define the English language dictionary
const char *english_dict[] = {
    "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet",
    "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango",
    "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"
};

// Translate an alien word to English
char *translate_alien_to_english(const char *alien_word) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(alien_word) * sizeof(char));

    // Translate each character in the alien word to its English equivalent
    for (int i = 0; i < strlen(alien_word); i++) {
        for (int j = 0; j < 26; j++) {
            if (alien_word[i] == alien_dict[j][0]) {
                english_translation[i] = english_dict[j][0];
            }
        }
    }

    // Return the English translation
    return english_translation;
}

// Translate an English word to alien
char *translate_english_to_alien(const char *english_word) {
    // Allocate memory for the alien translation
    char *alien_translation = malloc(strlen(english_word) * sizeof(char));

    // Translate each character in the English word to its alien equivalent
    for (int i = 0; i < strlen(english_word); i++) {
        for (int j = 0; j < 26; j++) {
            if (english_word[i] == english_dict[j][0]) {
                alien_translation[i] = alien_dict[j][0];
            }
        }
    }

    // Return the alien translation
    return alien_translation;
}

// Main function
int main() {
    // Get the alien word to be translated
    char alien_word[256];
    printf("Enter the alien word to be translated: ");
    scanf("%s", alien_word);

    // Translate the alien word to English
    char *english_translation = translate_alien_to_english(alien_word);

    // Print the English translation
    printf("The English translation is: %s\n", english_translation);

    // Get the English word to be translated
    char english_word[256];
    printf("Enter the English word to be translated: ");
    scanf("%s", english_word);

    // Translate the English word to alien
    char *alien_translation = translate_english_to_alien(english_word);

    // Print the alien translation
    printf("The alien translation is: %s\n", alien_translation);

    // Free the allocated memory
    free(english_translation);
    free(alien_translation);

    return 0;
}