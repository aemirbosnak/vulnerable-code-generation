//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
// Prepare the interstellar spaceship for a journey through the cosmos!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants to represent the Earth and alien languages.
#define EARTH_LANGUAGE "English"
#define ALIEN_LANGUAGE "Martian"

// Create a struct to represent the alien dictionary.
typedef struct {
    char earthWord[255];
    char alienWord[255];
} AlienDictionary;

// Initialize the alien dictionary with some common Earth and alien words.
AlienDictionary dictionary[] = {
    {"Hello", "Gloo"},
    {"Goodbye", "Fron"},
    {"Yes", "Taa"},
    {"No", "Nah"},
    {"Please", "Shaa"},
    {"Thank you", "Uraa"}
};

// Get the size of the alien dictionary.
int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

// Function to translate a word from Earth language to alien language.
char* translateToAlien(char* earthWord) {
    // Iterate over the dictionary to find the corresponding alien word.
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(earthWord, dictionary[i].earthWord) == 0) {
            // Return the alien word if found.
            return dictionary[i].alienWord;
        }
    }

    // Return NULL if the word is not found in the dictionary.
    return NULL;
}

// Function to translate a word from alien language to Earth language.
char* translateToEarth(char* alienWord) {
    // Iterate over the dictionary to find the corresponding Earth word.
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(alienWord, dictionary[i].alienWord) == 0) {
            // Return the Earth word if found.
            return dictionary[i].earthWord;
        }
    }

    // Return NULL if the word is not found in the dictionary.
    return NULL;
}

// Main function to interact with the user and translate words.
int main() {
    // Initialize variables to store the input and translated words.
    char inputWord[255];
    char* translatedWord;

    // Welcome the user to the alien language translator.
    printf("Welcome to the Alien Language Translator!\n");

    // Get the input word from the user.
    printf("Enter a word to translate: ");
    scanf("%s", inputWord);

    // Translate the word from Earth language to alien language.
    translatedWord = translateToAlien(inputWord);

    // Print the translated word.
    if (translatedWord != NULL) {
        printf("Translation to Martian: %s\n", translatedWord);
    } else {
        printf("Word not found in the dictionary.\n");
    }

    // Translate the word from alien language to Earth language.
    translatedWord = translateToEarth(inputWord);

    // Print the translated word.
    if (translatedWord != NULL) {
        printf("Translation to English: %s\n", translatedWord);
    } else {
        printf("Word not found in the dictionary.\n");
    }

    return 0;
}