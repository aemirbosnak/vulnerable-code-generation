//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
char *alien_dict[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d",
    "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
    "y", "z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", " ", ".", ",", "!", "?", "/", "\\", "\"",
    "'"
};

// Alien language translation function
char *translate_alien(char *alien_text) {
    // Allocate memory for the translated text
    char *translated_text = malloc(strlen(alien_text) + 1);
    if (translated_text == NULL) {
        return NULL;
    }

    // Translate each character in the alien text
    for (int i = 0; i < strlen(alien_text); i++) {
        char *alien_char = strchr(alien_dict, alien_text[i]);
        if (alien_char != NULL) {
            translated_text[i] = alien_char[1];
        } else {
            translated_text[i] = alien_text[i];
        }
    }

    // Add a null terminator to the end of the translated text
    translated_text[strlen(alien_text)] = '\0';

    // Return the translated text
    return translated_text;
}

// Main function
int main() {
    // Get the alien text from the user
    char alien_text[1024];
    printf("Enter the alien text to be translated: ");
    scanf("%s", alien_text);

    // Translate the alien text
    char *translated_text = translate_alien(alien_text);

    // Print the translated text
    printf("The translated text is: %s\n", translated_text);

    // Free the memory allocated for the translated text
    free(translated_text);

    return 0;
}