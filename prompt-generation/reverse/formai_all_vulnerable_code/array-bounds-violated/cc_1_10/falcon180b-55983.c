//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the alien alphabet
#define ALIEN_ALPHABET_SIZE 26
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyz";

// Define the translation table
char translation_table[26][26];

// Initialize the translation table
void init_translation_table() {
    int i, j;
    for (i = 0; i < ALIEN_ALPHABET_SIZE; i++) {
        for (j = 0; j < 26; j++) {
            translation_table[i][j] = 'a';
        }
    }
}

// Translate the given string to alien language
void translate(char* input) {
    int i = 0;
    while (*input) {
        if (isalpha(*input)) {
            if (isupper(*input)) {
                *input = alien_alphabet[i];
            } else {
                *input = alien_alphabet[i + 26];
            }
            i++;
            if (i >= ALIEN_ALPHABET_SIZE) {
                i = 0;
            }
        }
        input++;
    }
}

// Main function
int main() {
    char input[1000];

    // Initialize the translation table
    init_translation_table();

    // Get input from user
    printf("Enter the text to translate: ");
    fgets(input, sizeof(input), stdin);

    // Translate the input to alien language
    translate(input);

    // Print the translated text
    printf("Translated text: %s\n", input);

    return 0;
}