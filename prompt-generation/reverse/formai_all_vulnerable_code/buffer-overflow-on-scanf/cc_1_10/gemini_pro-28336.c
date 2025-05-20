//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alienDictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " ", ".", ",", "!",
    "?", ":", ";", "'", "\"", "(", ")", "[", "]", "{",
    "}"
};

// Define the English language dictionary
char *englishDictionary[] = {
    "apple", "banana", "cherry", "dog", "elephant", "fish",
    "grape", "horse", "ice cream", "juice", "kiwi", "lemon",
    "mango", "nut", "orange", "peach", "pineapple", "queen",
    "rabbit", "strawberry", "tiger", "umbrella", "violin",
    "watermelon", "x-ray", "yacht", "zebra"
};

// Function to translate an Alien word to English
char *translateAlienToEnglish(char *alienWord) {
    // Allocate memory for the English translation
    char *englishTranslation = malloc(strlen(alienWord) + 1);

    // Iterate over the characters in the Alien word
    for (int i = 0; i < strlen(alienWord); i++) {
        // Find the index of the Alien character in the Alien dictionary
        int alienIndex = -1;
        for (int j = 0; j < sizeof(alienDictionary) / sizeof(char *); j++) {
            if (strcmp(alienDictionary[j], &alienWord[i]) == 0) {
                alienIndex = j;
                break;
            }
        }

        // If the Alien character was found in the dictionary, translate it to English
        if (alienIndex != -1) {
            englishTranslation[i] = englishDictionary[alienIndex][0];
        } else {
            // If the Alien character was not found in the dictionary, leave it as it is
            englishTranslation[i] = alienWord[i];
        }
    }

    // Terminate the English translation with a null character
    englishTranslation[strlen(alienWord)] = '\0';

    // Return the English translation
    return englishTranslation;
}

// Function to translate an English word to Alien
char *translateEnglishToAlien(char *englishWord) {
    // Allocate memory for the Alien translation
    char *alienTranslation = malloc(strlen(englishWord) + 1);

    // Iterate over the characters in the English word
    for (int i = 0; i < strlen(englishWord); i++) {
        // Find the index of the English character in the English dictionary
        int englishIndex = -1;
        for (int j = 0; j < sizeof(englishDictionary) / sizeof(char *); j++) {
            if (strcmp(englishDictionary[j], &englishWord[i]) == 0) {
                englishIndex = j;
                break;
            }
        }

        // If the English character was found in the dictionary, translate it to Alien
        if (englishIndex != -1) {
            alienTranslation[i] = alienDictionary[englishIndex][0];
        } else {
            // If the English character was not found in the dictionary, leave it as it is
            alienTranslation[i] = englishWord[i];
        }
    }

    // Terminate the Alien translation with a null character
    alienTranslation[strlen(englishWord)] = '\0';

    // Return the Alien translation
    return alienTranslation;
}

// Main function
int main() {
    // Get the Alien word from the user
    char alienWord[100];
    printf("Enter an Alien word: ");
    scanf("%s", alienWord);

    // Translate the Alien word to English
    char *englishTranslation = translateAlienToEnglish(alienWord);

    // Print the English translation
    printf("English translation: %s\n", englishTranslation);

    // Free the memory allocated for the English translation
    free(englishTranslation);

    // Get the English word from the user
    char englishWord[100];
    printf("Enter an English word: ");
    scanf("%s", englishWord);

    // Translate the English word to Alien
    char *alienTranslation = translateEnglishToAlien(englishWord);

    // Print the Alien translation
    printf("Alien translation: %s\n", alienTranslation);

    // Free the memory allocated for the Alien translation
    free(alienTranslation);

    return 0;
}