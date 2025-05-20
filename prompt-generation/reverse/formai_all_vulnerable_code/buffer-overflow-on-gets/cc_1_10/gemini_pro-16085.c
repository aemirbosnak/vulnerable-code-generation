//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char* alien_dict[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", " ", ".", ",", "!",
    "?", ":", ";", "'", "\"", "\\", "/", "(", ")", "[",
    "]", "{", "}", "|", "<", ">", "=", "+", "-", "*",
    "&", "%", "$", "#", "@", "~", "`", "^"
};

// Get the length of the Alien language dictionary
int alien_dict_len = sizeof(alien_dict) / sizeof(char*);

// Function to translate a string from English to Alien
char* translate_to_alien(char* english) {
    // Allocate memory for the Alien translation
    char* alien = malloc(strlen(english) + 1);

    // Translate each character in the English string to Alien
    int i;
    for (i = 0; i < strlen(english); i++) {
        // Find the index of the English character in the dictionary
        int index = -1;
        int j;
        for (j = 0; j < alien_dict_len; j++) {
            if (english[i] == alien_dict[j][0]) {
                index = j;
                break;
            }
        }

        // If the character is not found in the dictionary, replace it with a space
        if (index == -1) {
            alien[i] = ' ';
        } else {
            // Copy the Alien character to the translation
            alien[i] = alien_dict[index][1];
        }
    }

    // Add a null terminator to the end of the Alien translation
    alien[strlen(english)] = '\0';

    // Return the Alien translation
    return alien;
}

// Function to translate a string from Alien to English
char* translate_to_english(char* alien) {
    // Allocate memory for the English translation
    char* english = malloc(strlen(alien) + 1);

    // Translate each character in the Alien string to English
    int i;
    for (i = 0; i < strlen(alien); i++) {
        // Find the index of the Alien character in the dictionary
        int index = -1;
        int j;
        for (j = 0; j < alien_dict_len; j++) {
            if (alien[i] == alien_dict[j][1]) {
                index = j;
                break;
            }
        }

        // If the character is not found in the dictionary, replace it with a space
        if (index == -1) {
            english[i] = ' ';
        } else {
            // Copy the English character to the translation
            english[i] = alien_dict[index][0];
        }
    }

    // Add a null terminator to the end of the English translation
    english[strlen(alien)] = '\0';

    // Return the English translation
    return english;
}

// Main function
int main() {
    // Get the English string from the user
    char english[1024];
    printf("Enter an English string: ");
    gets(english);

    // Translate the English string to Alien
    char* alien = translate_to_alien(english);

    // Print the Alien translation
    printf("Alien translation: %s\n", alien);

    // Translate the Alien string back to English
    char* english2 = translate_to_english(alien);

    // Print the English translation
    printf("English translation: %s\n", english2);

    // Free the memory allocated for the translations
    free(alien);
    free(english2);

    return 0;
}