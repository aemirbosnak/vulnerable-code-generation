//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Alien language grammar rules
const char *alien_grammar[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z"
};

// Function to translate alien language to English
char *alien_to_english(const char *alien_text) {
    // Allocate memory for the English translation
    char *english_text = malloc(strlen(alien_text) + 1);

    // Initialize the English translation to empty string
    english_text[0] = '\0';

    // Iterate over the alien text
    for (int i = 0; alien_text[i] != '\0'; i++) {
        // Find the corresponding English character in the dictionary
        for (int j = 0; j < 26; j++) {
            if (alien_text[i] == alien_dict[j][0]) {
                // Append the English character to the translation
                strcat(english_text, alien_grammar[j]);
                break;
            }
        }
    }

    // Return the English translation
    return english_text;
}

// Function to translate English to alien language
char *english_to_alien(const char *english_text) {
    // Allocate memory for the alien language translation
    char *alien_text = malloc(strlen(english_text) + 1);

    // Initialize the alien language translation to empty string
    alien_text[0] = '\0';

    // Iterate over the English text
    for (int i = 0; english_text[i] != '\0'; i++) {
        // Find the corresponding alien language character in the grammar
        for (int j = 0; j < 26; j++) {
            if (english_text[i] == alien_grammar[j][0]) {
                // Append the alien language character to the translation
                strcat(alien_text, alien_dict[j]);
                break;
            }
        }
    }

    // Return the alien language translation
    return alien_text;
}

// Main function
int main() {
    // Get the alien language text from the user
    char alien_text[100];
    printf("Enter the alien language text: ");
    scanf("%s", alien_text);

    // Translate the alien language text to English
    char *english_text = alien_to_english(alien_text);

    // Print the English translation
    printf("English translation: %s\n", english_text);

    // Translate the English text to alien language
    char *alien_text2 = english_to_alien(english_text);

    // Print the alien language translation
    printf("Alien language translation: %s\n", alien_text2);

    // Free the allocated memory
    free(english_text);
    free(alien_text2);

    return 0;
}