//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
typedef struct {
    char *alienWord;
    char *englishTranslation;
} AlienDictionaryEntry;

// Create an array of alien language dictionary entries
AlienDictionaryEntry alienDictionary[] = {
    { "Akk", "Love" },
    { "Bar", "Peace" },
    { "Car", "Hope" },
    { "Dar", "Joy" },
    { "Ear", "Happiness" }
};

// Get the number of entries in the alien language dictionary
int numAlienDictionaryEntries = sizeof(alienDictionary) / sizeof(AlienDictionaryEntry);

// Translate an alien word to English
char *translateAlienWord(char *alienWord) {
    // Iterate over the alien language dictionary
    for (int i = 0; i < numAlienDictionaryEntries; i++) {
        // Check if the alien word matches the current dictionary entry
        if (strcmp(alienWord, alienDictionary[i].alienWord) == 0) {
            // Return the English translation of the alien word
            return alienDictionary[i].englishTranslation;
        }
    }

    // If the alien word is not found in the dictionary, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the alien word from the user
    char alienWord[256];
    printf("Enter the alien word you want to translate: ");
    scanf("%s", alienWord);

    // Translate the alien word to English
    char *englishTranslation = translateAlienWord(alienWord);

    // Print the English translation of the alien word
    if (englishTranslation != NULL) {
        printf("The English translation of '%s' is '%s'\n", alienWord, englishTranslation);
    } else {
        printf("The alien word '%s' is not found in the dictionary\n", alienWord);
    }

    return 0;
}