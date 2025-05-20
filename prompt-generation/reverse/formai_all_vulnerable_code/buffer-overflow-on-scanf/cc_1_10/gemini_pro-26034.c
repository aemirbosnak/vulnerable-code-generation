//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// Alien language dictionary
char *alien_dict[] = {
    "a", "b", "c", "d", "e",
    "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o",
    "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y",
    "z", "aa", "ab", "ac", "ad",
    "ae", "af", "ag", "ah", "ai",
    "aj", "ak", "al", "am", "an",
    "ao", "ap", "aq", "ar", "as",
    "at", "au", "av", "aw", "ax",
    "ay", "az"
};

// Number of words in the alien language dictionary
int num_alien_words = sizeof(alien_dict) / sizeof(char *);

// Function to translate an English word to Alien language
char *english_to_alien(char *english_word) {
    // Allocate memory for the translated word
    char *alien_word = malloc(MAX_WORD_LEN * sizeof(char));

    // Iterate over the characters in the English word
    int i = 0;
    while (english_word[i] != '\0') {
        // Find the corresponding alien letter in the dictionary
        int j = 0;
        while (strcmp(alien_dict[j], english_word + i) != 0) {
            j++;
        }

        // Append the alien letter to the translated word
        alien_word[i] = j + 'a';

        // Increment the index of the character in the English word
        i++;
    }

    // Add the null-terminator to the translated word
    alien_word[i] = '\0';

    // Return the translated word
    return alien_word;
}

// Function to translate an Alien language word to English
char *alien_to_english(char *alien_word) {
    // Allocate memory for the translated word
    char *english_word = malloc(MAX_WORD_LEN * sizeof(char));

    // Iterate over the characters in the Alien language word
    int i = 0;
    while (alien_word[i] != '\0') {
        // Find the corresponding English letter in the dictionary
        int j = alien_word[i] - 'a';

        // Append the English letter to the translated word
        english_word[i] = alien_dict[j];

        // Increment the index of the character in the Alien language word
        i++;
    }

    // Add the null-terminator to the translated word
    english_word[i] = '\0';

    // Return the translated word
    return english_word;
}

// Main function
int main() {
    // Get the English word to be translated
    char english_word[MAX_WORD_LEN];
    printf("Enter an English word: ");
    scanf("%s", english_word);

    // Translate the English word to Alien language
    char *alien_word = english_to_alien(english_word);

    // Print the translated word
    printf("Alien language translation: %s\n", alien_word);

    // Translate the Alien language word back to English
    char *english_word_back = alien_to_english(alien_word);

    // Print the translated word
    printf("English translation back: %s\n", english_word_back);

    // Free the allocated memory
    free(alien_word);
    free(english_word_back);

    return 0;
}