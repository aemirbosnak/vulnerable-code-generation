//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

// Alien Language Constants
#define ALIEN_START_SYMBOL 'Z'
#define ENGLISH_START_SYMBOL 'A'
#define ALIEN_VOWELS "AIUEO"
#define ENGLISH_VOWELS "AEIOU"
#define ALIEN_CONSONANTS "BCDFGHJKLMNPQRSTVWXY"
#define ENGLISH_CONSONANTS "BCDFGHJKLMNPQRSTVWXYZ"
#define MAX_INPUT_LENGTH 100

// Function to check if a given character is a vowel or consonant
int is_vowel(char c) {
    int i;
    for (i = 0; i < strlen(ALIEN_VOWELS); i++) {
        if (ALIEN_VOWELS[i] == c) return 1;
    }
    return 0;
}

// Function to translate an Alien Language character to its English equivalent
char alien_to_english(char c) {
    if (is_vowel(c)) {
        int i;
        for (i = 0; i < strlen(ENGLISH_VOWELS); i++) {
            if (ALIEN_VOWELS[i] == c) return ENGLISH_VOWELS[i];
        }
        // Unknown vowel, assume it's a silent character
        return ' ';
    } else {
        int i;
        for (i = 0; i < strlen(ALIEN_CONSONANTS); i++) {
            if (ALIEN_CONSONANTS[i] == c) return ENGLISH_CONSONANTS[i];
        }
        // Unknown consonant, assume it's a silent character
        return ' ';
    }
}

// Function to translate an Alien Language string to English
void translate_alien(char *alien) {
    int i, j;
    char english[MAX_INPUT_LENGTH];
    english[0] = ENGLISH_START_SYMBOL;

    for (i = 0; alien[i] != '\0'; i++) {
        if (i > 0 && alien[i-1] != ALIEN_START_SYMBOL) {
            english[i] = alien_to_english(alien[i]);
        }
    }

    // Replace the last Alien Language character with its English equivalent and add a null terminator
    english[i] = alien_to_english(ALIEN_START_SYMBOL);
    english[++i] = '\0';

    printf("The English translation of '%s' is '%s'\n", alien, english);
}

int main() {
    char alien_input[MAX_INPUT_LENGTH];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter an Alien Language string (starting with '%c'): ", ALIEN_START_SYMBOL);
    scanf("%s", alien_input);

    // Check if the given input string is valid Alien Language
    if (alien_input[0] != ALIEN_START_SYMBOL || alien_input[strlen(alien_input)-1] != ALIEN_START_SYMBOL) {
        printf("Invalid Alien Language input! It must start and end with '%c'.\n", ALIEN_START_SYMBOL);
        return 1;
    }

    translate_alien(alien_input);

    printf("\nThank you for using the Alien Language Translator! Have a great day!\n");

    return 0;
}