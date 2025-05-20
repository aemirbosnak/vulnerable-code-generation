//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
struct AlienDictionary {
    char *alienWord;
    char *englishTranslation;
};

// Create an array of Alien dictionary entries
struct AlienDictionary dictionary[] = {
    {"kloog", "hello"},
    {"plooze", "goodbye"},
    {"frizza", "friend"},
    {"glup", "eat"},
    {"moop", "sleep"}
};

// Get the number of entries in the dictionary
int numEntries = sizeof(dictionary) / sizeof(dictionary[0]);

// Translate an Alien word to English
char *translateAlienToEnglish(char *alienWord) {
    // Iterate over the dictionary entries
    for (int i = 0; i < numEntries; i++) {
        // Check if the Alien word matches the dictionary entry
        if (strcmp(alienWord, dictionary[i].alienWord) == 0) {
            // Return the English translation
            return dictionary[i].englishTranslation;
        }
    }

    // If the Alien word is not found in the dictionary, return NULL
    return NULL;
}

// Translate an English word to Alien
char *translateEnglishToAlien(char *englishWord) {
    // Iterate over the dictionary entries
    for (int i = 0; i < numEntries; i++) {
        // Check if the English word matches the dictionary entry
        if (strcmp(englishWord, dictionary[i].englishTranslation) == 0) {
            // Return the Alien word
            return dictionary[i].alienWord;
        }
    }

    // If the English word is not found in the dictionary, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the Alien word to translate
    char alienWord[256];
    printf("Enter the Alien word to translate: ");
    scanf("%s", alienWord);

    // Translate the Alien word to English
    char *englishTranslation = translateAlienToEnglish(alienWord);

    // Print the English translation
    if (englishTranslation != NULL) {
        printf("The English translation is: %s\n", englishTranslation);
    } else {
        printf("The Alien word is not found in the dictionary.\n");
    }

    // Get the English word to translate
    char englishWord[256];
    printf("Enter the English word to translate: ");
    scanf("%s", englishWord);

    // Translate the English word to Alien
    char *alienTranslation = translateEnglishToAlien(englishWord);

    // Print the Alien translation
    if (alienTranslation != NULL) {
        printf("The Alien translation is: %s\n", alienTranslation);
    } else {
        printf("The English word is not found in the dictionary.\n");
    }

    return 0;
}