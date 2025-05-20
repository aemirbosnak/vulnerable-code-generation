//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien Language dictionary
typedef struct {
    char alien_word[32];  // Alien word
    char english_translation[32];  // English translation
} AlienLanguageDictionaryEntry;

// Create an array of Alien Language dictionary entries
AlienLanguageDictionaryEntry dictionary[] = {
    {"AB", "Hello"},
    {"BA", "World"},
    {"ABAB", "Computer"},
    {"BABA", "Alien"},
    {"ABABA", "Language"},
    {"BABABA", "Translator"}
};

// Get the number of entries in the Alien Language dictionary
int num_dictionary_entries = sizeof(dictionary) / sizeof(AlienLanguageDictionaryEntry);

// Function to translate an Alien word to English
char *translate_alien_word_to_english(char *alien_word) {
    // Search the Alien Language dictionary for the Alien word
    for (int i = 0; i < num_dictionary_entries; i++) {
        if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
            // Alien word found in the dictionary, return the English translation
            return dictionary[i].english_translation;
        }
    }

    // Alien word not found in the dictionary, return NULL
    return NULL;
}

// Function to translate an English word to Alien
char *translate_english_word_to_alien(char *english_word) {
    // Search the Alien Language dictionary for the English word
    for (int i = 0; i < num_dictionary_entries; i++) {
        if (strcmp(english_word, dictionary[i].english_translation) == 0) {
            // English word found in the dictionary, return the Alien translation
            return dictionary[i].alien_word;
        }
    }

    // English word not found in the dictionary, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the Alien word to translate
    char alien_word[32];
    printf("Enter the Alien word to translate: ");
    scanf("%s", alien_word);

    // Translate the Alien word to English
    char *english_translation = translate_alien_word_to_english(alien_word);

    // If the Alien word was found in the dictionary, print the English translation
    if (english_translation != NULL) {
        printf("The English translation of '%s' is '%s'\n", alien_word, english_translation);
    } else {
        printf("Alien word '%s' not found in the dictionary\n", alien_word);
    }

    // Get the English word to translate
    char english_word[32];
    printf("\nEnter the English word to translate: ");
    scanf("%s", english_word);

    // Translate the English word to Alien
    char *alien_translation = translate_english_word_to_alien(english_word);

    // If the English word was found in the dictionary, print the Alien translation
    if (alien_translation != NULL) {
        printf("The Alien translation of '%s' is '%s'\n", english_word, alien_translation);
    } else {
        printf("English word '%s' not found in the dictionary\n", english_word);
    }

    return 0;
}