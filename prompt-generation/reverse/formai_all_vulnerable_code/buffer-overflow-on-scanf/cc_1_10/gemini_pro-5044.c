//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9", " ", ".", ",", "!",
    "?", ":", ";", "-", "_", "=", "+", "/", "*", "%",
    "^", "(", ")", "[", "]", "{", "}", "<", ">", "|",
    "~"
};

// Define the English language dictionary
const char *english_dict[] = {
    "a", "bee", "see", "dee", "e", "eff", "gee", "aitch", "eye", "jay",
    "kay", "ell", "em", "en", "oh", "pee", "cue", "are", "ess", "tee",
    "you", "vee", "double-you", "ex", "why", "zee", "zero", "one", "two", "three",
    "four", "five", "six", "seven", "eight", "nine", "space", "period", "comma", "exclamation",
    "question", "colon", "semi-colon", "hyphen", "underscore", "equals", "plus", "slash", "asterisk", "percent",
    "caret", "left-parenthesis", "right-parenthesis", "left-bracket", "right-bracket", "left-brace", "right-brace", "less-than", "greater-than", "pipe",
    "tilde"
};

// Translate an alien word to English
char *alien_to_english(const char *alien_word) {
    // Allocate memory for the English word
    char *english_word = malloc(strlen(alien_word) + 1);
    if (english_word == NULL) {
        return NULL;
    }

    // Translate the alien word to English
    int i;
    for (i = 0; i < strlen(alien_word); i++) {
        int index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(alien_dict[0]); j++) {
            if (strcmp(alien_word[i], alien_dict[j]) == 0) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            // The alien word is not in the dictionary
            free(english_word);
            return NULL;
        }
        english_word[i] = english_dict[index];
    }

    // Null-terminate the English word
    english_word[strlen(alien_word)] = '\0';

    // Return the English word
    return english_word;
}

// Translate an English word to alien
char *english_to_alien(const char *english_word) {
    // Allocate memory for the alien word
    char *alien_word = malloc(strlen(english_word) + 1);
    if (alien_word == NULL) {
        return NULL;
    }

    // Translate the English word to alien
    int i;
    for (i = 0; i < strlen(english_word); i++) {
        int index = -1;
        for (int j = 0; j < sizeof(english_dict) / sizeof(english_dict[0]); j++) {
            if (strcmp(english_word[i], english_dict[j]) == 0) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            // The English word is not in the dictionary
            free(alien_word);
            return NULL;
        }
        alien_word[i] = alien_dict[index];
    }

    // Null-terminate the alien word
    alien_word[strlen(english_word)] = '\0';

    // Return the alien word
    return alien_word;
}

// Test the alien language translator
int main() {
    // Get the alien word from the user
    char *alien_word = malloc(100);
    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word to English
    char *english_word = alien_to_english(alien_word);
    if (english_word == NULL) {
        printf("Invalid alien word\n");
        return 1;
    }

    // Print the English word
    printf("English word: %s\n", english_word);

    // Free the memory allocated for the English word
    free(english_word);

    // Get the English word from the user
    char *english_word1 = malloc(100);
    printf("Enter an English word: ");
    scanf("%s", english_word1);

    // Translate the English word to alien
    char *alien_word1 = english_to_alien(english_word1);
    if (alien_word1 == NULL) {
        printf("Invalid English word\n");
        return 1;
    }

    // Print the alien word
    printf("Alien word: %s\n", alien_word1);

    // Free the memory allocated for the alien word
    free(alien_word1);

    // Free the memory allocated for the alien word
    free(alien_word);

    return 0;
}