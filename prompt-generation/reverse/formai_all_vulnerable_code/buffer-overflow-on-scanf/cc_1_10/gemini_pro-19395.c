//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien Language dictionary
char *alien_language[] = {
    "AA", "BB", "CC", "DD", "EE", "FF", "GG", "HH", "II", "JJ",
    "KK", "LL", "MM", "NN", "OO", "PP", "QQ", "RR", "SS", "TT",
    "UU", "VV", "WW", "XX", "YY", "ZZ"
};

// Define the English Language dictionary
char *english_language[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z"
};

// Function to translate an Alien Language word to English
char *translate_alien_to_english(char *alien_word) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(alien_word) + 1);

    // Iterate over the characters in the Alien Language word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the index of the character in the Alien Language dictionary
        int index = -1;
        for (int j = 0; j < 26; j++) {
            if (strcmp(alien_language[j], alien_word[i]) == 0) {
                index = j;
                break;
            }
        }

        // If the character was not found in the Alien Language dictionary, return NULL
        if (index == -1) {
            return NULL;
        }

        // Add the English translation of the character to the English translation string
        english_translation[i] = english_language[index];
    }

    // Add the null terminator to the English translation string
    english_translation[strlen(alien_word)] = '\0';

    // Return the English translation string
    return english_translation;
}

// Function to translate an English word to Alien Language
char *translate_english_to_alien(char *english_word) {
    // Allocate memory for the Alien Language translation
    char *alien_translation = malloc(strlen(english_word) + 1);

    // Iterate over the characters in the English word
    for (int i = 0; i < strlen(english_word); i++) {
        // Find the index of the character in the English Language dictionary
        int index = -1;
        for (int j = 0; j < 26; j++) {
            if (strcmp(english_language[j], english_word[i]) == 0) {
                index = j;
                break;
            }
        }

        // If the character was not found in the English Language dictionary, return NULL
        if (index == -1) {
            return NULL;
        }

        // Add the Alien Language translation of the character to the Alien Language translation string
        alien_translation[i] = alien_language[index];
    }

    // Add the null terminator to the Alien Language translation string
    alien_translation[strlen(english_word)] = '\0';

    // Return the Alien Language translation string
    return alien_translation;
}

// Main function
int main() {
    // Get the Alien Language word from the user
    char alien_word[256];
    printf("Enter an Alien Language word: ");
    scanf("%s", alien_word);

    // Translate the Alien Language word to English
    char *english_translation = translate_alien_to_english(alien_word);

    // If the translation was successful, print the English translation
    if (english_translation != NULL) {
        printf("English translation: %s\n", english_translation);
    } else {
        printf("Invalid Alien Language word.\n");
    }

    // Get the English word from the user
    char english_word[256];
    printf("Enter an English word: ");
    scanf("%s", english_word);

    // Translate the English word to Alien Language
    char *alien_translation = translate_english_to_alien(english_word);

    // If the translation was successful, print the Alien Language translation
    if (alien_translation != NULL) {
        printf("Alien Language translation: %s\n", alien_translation);
    } else {
        printf("Invalid English word.\n");
    }

    // Free the memory allocated for the translations
    free(english_translation);
    free(alien_translation);

    return 0;
}