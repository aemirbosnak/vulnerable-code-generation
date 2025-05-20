//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Define the alphabet for the alien language
#define ALIEN_ALPHABET "abcdefghij"

// Define the mapping between the alien alphabet and English letters
#define ENGLISH_ALPHABET "abcdefghijklmnopqrstuvwxyz"

/**
 * Function to translate a given string from the alien language to English.
 * 
 * @param alienStr The string to be translated.
 * @param length The length of the given string.
 * @return The translated string.
 */
char* translateFromAlien(char* alienStr, int length) {
    //Create a mapping array to map the alien language alphabet with English alphabet
    char map[26] = {0};
    for (int i = 0; ENGLISH_ALPHABET[i] != '\0'; ++i) {
        char englishChar = ENGLISH_ALPHABET[i];
        char alienChar = ALIEN_ALPHABET[i];

        map[alienChar - 'a'] = englishChar;
    }

    // Translate the given string using the mapping
    for (int i = 0; i < length; i++) {
        char currChar = alienStr[i];
        if(currChar == ' ') continue; //skip the space
        alienStr[i] = map[currChar - 'a'];
    }

    return alienStr;
}

/**
 * Function to translate a given string from English to the alien language.
 * 
 * @param englishStr The string to be translated.
 * @param length The length of the given string.
 * @return The translated string.
 */
char* translateToAlien(char* englishStr, int length) {
    //Create a mapping array to map the English alphabet with alien language alphabet 
    char map[26] = { 0 };
    for (int i = 0; ALIEN_ALPHABET[i] != '\0'; ++i) {
        char alienChar = ALIEN_ALPHABET[i];
        char englishChar = ENGLISH_ALPHABET[i];

        map[englishChar - 'a'] = alienChar;
    }

    // Translate the given string using the mapping
    for (int i = 0; i < length; i++) {
        char currChar = englishStr[i];
        if(currChar == ' ') continue; //skip the space
        englishStr[i] = map[currChar - 'a'];
    }

    return englishStr;
}

int main() {
    char alienStr[] = "ab cd ef";
    char englishStr[] = "hello world";

    printf("Alien language: %s\n", alienStr);
    printf("Translated to English: %s\n", translateFromAlien(alienStr, strlen(alienStr)));
    printf("English: %s\n", englishStr);
    printf("Translated to Alien language: %s\n", translateToAlien(englishStr, strlen(englishStr)));

    return 0;
}