//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
// Galactic Federation Alien Language Translator v1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
struct AlienDictEntry {
    char alienWord[16];
    char englishTranslation[32];
};

// Initialize the alien language dictionary
struct AlienDictEntry dictionary[] = {
    {"slithy", "lithe and active"},
    {"tove", "disembowel"},
    {"mimsy", "flimsy and weak"},
    {"borogoves", "nonsense"},
    {"frumious", "furious"},
    {"Bandersnatch", "imaginary creature"},
    {"Jabberwocky", "nonsense creature"}
};

// Get the number of entries in the dictionary
int numEntries = sizeof(dictionary) / sizeof(struct AlienDictEntry);

// Translate an alien word to English
char *translateAlienWord(char *alienWord) {
    // Iterate through the dictionary to find a match
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(dictionary[i].alienWord, alienWord) == 0) {
            // Return the English translation
            return dictionary[i].englishTranslation;
        }
    }

    // Return a message if no match is found
    return "Unknown alien word";
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Galactic Federation Alien Language Translator v1.0!\n");

    // Get the alien word to translate
    char alienWord[16];
    printf("Enter an alien word to translate: ");
    scanf("%s", alienWord);

    // Translate the alien word
    char *englishTranslation = translateAlienWord(alienWord);

    // Print the translation
    printf("English translation: %s\n", englishTranslation);

    return 0;
}