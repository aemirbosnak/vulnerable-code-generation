//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
const char *alienDictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " "
};

// Function to translate an Alien word into English
char *translateAlienWord(const char *alienWord) {
    // Allocate memory for the translated word
    char *translatedWord = malloc(strlen(alienWord) + 1);

    // Translate the Alien word character by character
    for (int i = 0; i < strlen(alienWord); i++) {
        // Find the corresponding English character in the dictionary
        for (int j = 0; j < 27; j++) {
            if (alienWord[i] == alienDictionary[j][0]) {
                translatedWord[i] = alienDictionary[j][1];
                break;
            }
        }
    }

    // Null-terminate the translated word
    translatedWord[strlen(alienWord)] = '\0';

    // Return the translated word
    return translatedWord;
}

// Function to translate an English word into Alien
char *translateEnglishWord(const char *englishWord) {
    // Allocate memory for the translated word
    char *translatedWord = malloc(strlen(englishWord) + 1);

    // Translate the English word character by character
    for (int i = 0; i < strlen(englishWord); i++) {
        // Find the corresponding Alien character in the dictionary
        for (int j = 0; j < 27; j++) {
            if (englishWord[i] == alienDictionary[j][1]) {
                translatedWord[i] = alienDictionary[j][0];
                break;
            }
        }
    }

    // Null-terminate the translated word
    translatedWord[strlen(englishWord)] = '\0';

    // Return the translated word
    return translatedWord;
}

// Main function
int main() {
    // Get the Alien word from the user
    char alienWord[100];
    printf("Enter an Alien word: ");
    scanf("%s", alienWord);

    // Translate the Alien word into English
    char *translatedWord = translateAlienWord(alienWord);

    // Print the translated word
    printf("The English translation of the Alien word is: %s\n", translatedWord);

    // Get the English word from the user
    char englishWord[100];
    printf("Enter an English word: ");
    scanf("%s", englishWord);

    // Translate the English word into Alien
    translatedWord = translateEnglishWord(englishWord);

    // Print the translated word
    printf("The Alien translation of the English word is: %s\n", translatedWord);

    // Free the allocated memory
    free(translatedWord);

    return 0;
}