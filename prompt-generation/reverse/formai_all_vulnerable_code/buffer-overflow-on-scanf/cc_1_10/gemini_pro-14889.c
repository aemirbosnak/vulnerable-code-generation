//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    ",", ".", "?", "!",
    " ",
};

// Alien language codes
const char *alien_codes[] = {
    "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111",
    "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111",
    "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001",
    "0000", "0001", "0010", "0011",
    "0000",
};

// Translate a string from English to Alien language
char *translate_to_alien(const char *english) {
    // Allocate memory for the translated string
    char *alien = malloc(strlen(english) * 4 + 1);

    // Translate each character in the English string
    int i = 0;
    while (english[i] != '\0') {
        // Find the Alien language code for the current character
        int code_index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char *); j++) {
            if (strcmp(alien_dict[j], &english[i]) == 0) {
                code_index = j;
                break;
            }
        }

        // If the character is not found in the dictionary, use the default code
        if (code_index == -1) {
            code_index = 0;
        }

        // Append the Alien language code to the translated string
        strcat(alien, alien_codes[code_index]);

        // Increment the index of the current character
        i++;
    }

    // Return the translated string
    return alien;
}

// Translate a string from Alien language to English
char *translate_from_alien(const char *alien) {
    // Allocate memory for the translated string
    char *english = malloc(strlen(alien) / 4 + 1);

    // Translate each 4-bit code in the Alien language string
    int i = 0;
    while (alien[i] != '\0') {
        // Get the 4-bit code for the current character
        char code[5];
        strncpy(code, &alien[i], 4);
        code[4] = '\0';

        // Find the English character for the current code
        char *english_char = NULL;
        for (int j = 0; j < sizeof(alien_codes) / sizeof(char *); j++) {
            if (strcmp(alien_codes[j], code) == 0) {
                english_char = alien_dict[j];
                break;
            }
        }

        // If the code is not found in the dictionary, use the default character
        if (english_char == NULL) {
            english_char = " ";
        }

        // Append the English character to the translated string
        strcat(english, english_char);

        // Increment the index of the current character
        i += 4;
    }

    // Return the translated string
    return english;
}

// Main function
int main() {
    // Get the English string from the user
    char english[100];
    printf("Enter an English string: ");
    scanf("%s", english);

    // Translate the English string to Alien language
    char *alien = translate_to_alien(english);

    // Print the translated string
    printf("Alien language translation: %s\n", alien);

    // Translate the Alien language string back to English
    char *english_back = translate_from_alien(alien);

    // Print the translated string
    printf("English translation back: %s\n", english_back);

    // Free the allocated memory
    free(alien);
    free(english_back);

    return 0;
}