//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ".", ",", "!",
    "?", ":", ";", "'", "\"", "(", ")", "[", "]", "{",
    "}", "0", "1", "2", "3", "4", "5", "6", "7", "8",
    "9",
};

// Define the English language dictionary
const char *english_dict[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", " ", ".", ",", "!",
    "?", ":", ";", "'", "\"", "(", ")", "[", "]", "{",
    "}", "0", "1", "2", "3", "4", "5", "6", "7", "8",
    "9",
};

// Translate a character from alien to English
char translate_char(char c) {
    for (int i = 0; i < 52; i++) {
        if (alien_dict[i][0] == c) {
            return english_dict[i][0];
        }
    }
    return c;
}

// Translate a string from alien to English
char *translate_string(char *s) {
    char *t = malloc(strlen(s) + 1);
    for (int i = 0; i < strlen(s); i++) {
        t[i] = translate_char(s[i]);
    }
    t[strlen(s)] = '\0';
    return t;
}

// Main function
int main() {
    // Get the alien string from the user
    char *s = malloc(100);
    printf("Enter the alien string: ");
    scanf("%s", s);

    // Translate the alien string to English
    char *t = translate_string(s);

    // Print the translated string
    printf("The English translation is: %s\n", t);

    // Free the allocated memory
    free(s);
    free(t);

    return 0;
}