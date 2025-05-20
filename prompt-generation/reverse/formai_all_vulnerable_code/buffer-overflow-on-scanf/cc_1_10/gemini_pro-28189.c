//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
char *alien_dict[26] = {
    "Nttz-ya", "Vae", "Pn", "Gk", "L", "C", "Aa", "Gt", "Du", "Sr", "F", "Mg", "Au", "N", "Pn-n",
    "Gk-k", "L-l", "C-c", "Aa-a", "Gt-g", "Du-d", "Sr-s", "F-f", "Mg-m", "Au-u"
};

// Function to translate an alien word into English
char *translate_alien(char *alien_word) {
    // Allocate memory for the English translation
    char *english_translation = malloc(strlen(alien_word) + 1);

    // Translate each character of the alien word
    for (int i = 0; i < strlen(alien_word); i++) {
        // Find the index of the character in the alien dictionary
        int index = alien_word[i] - 'a';

        // Copy the English translation of the character to the English translation string
        english_translation[i] = alien_dict[index][0];
    }

    // Add the null terminator to the English translation string
    english_translation[strlen(alien_word)] = '\0';

    // Return the English translation
    return english_translation;
}

// Function to translate an English word into Alien
char *translate_english(char *english_word) {
    // Allocate memory for the Alien translation
    char *alien_translation = malloc(strlen(english_word) + 1);

    // Translate each character of the English word
    for (int i = 0; i < strlen(english_word); i++) {
        // Find the index of the character in the alien dictionary
        int index = 0;
        while (alien_dict[index][0] != english_word[i]) {
            index++;
        }

        // Copy the Alien translation of the character to the Alien translation string
        alien_translation[i] = 'a' + index;
    }

    // Add the null terminator to the Alien translation string
    alien_translation[strlen(english_word)] = '\0';

    // Return the Alien translation
    return alien_translation;
}

// Main function
int main() {
    // Get the alien word from the user
    char alien_word[101];
    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word into English
    char *english_translation = translate_alien(alien_word);

    // Print the English translation
    printf("English translation: %s\n", english_translation);

    // Get the English word from the user
    char english_word[101];
    printf("Enter an English word: ");
    scanf("%s", english_word);

    // Translate the English word into Alien
    char *alien_translation = translate_english(english_word);

    // Print the Alien translation
    printf("Alien translation: %s\n", alien_translation);

    // Free the memory allocated for the translations
    free(english_translation);
    free(alien_translation);

    return 0;
}