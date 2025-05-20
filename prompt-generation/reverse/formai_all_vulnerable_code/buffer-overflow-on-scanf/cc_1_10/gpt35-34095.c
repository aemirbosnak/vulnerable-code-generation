//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for alien language translation
#define LETTERS 26
#define ALIEN_LETTERS 7
#define ALIEN_ALPHABET {"A","B","C","D","E","F","G"}
#define HUMAN_ALPHABET {"a","b","c","d","e","f","g"}
#define DEFAULT_TRANSLATION "?"

// Define function to translate letter from alien to human language
char* translateLetter(char* letter, char** alienAlphabet, char** humanAlphabet) {
    // Loop through alien alphabet to find corresponding human letter
    for (int i = 0; i < ALIEN_LETTERS; i++) {
        if (strcmp(letter, alienAlphabet[i]) == 0) {
            return humanAlphabet[i];
        }
    }
    // Return default translation if letter not found
    return DEFAULT_TRANSLATION;
}

// Define function to translate word from alien to human language
char* translateWord(char* word, char** alienAlphabet, char** humanAlphabet) {
    int length = strlen(word);
    char* result = (char*) malloc(sizeof(char) * length);
    // Loop through each letter in word and translate from alien to human language
    for (int i = 0; i < length; i++) {
        char* letter = (char*) malloc(sizeof(char));
        strncpy(letter, &word[i], 1);
        char* translation = translateLetter(letter, alienAlphabet, humanAlphabet);
        strncat(result, translation, 1);
    }
    return result;
}

// Define main function
int main() {
    // Define variables to hold alien and human alphabet
    char* alienAlphabet[ALIEN_LETTERS] = ALIEN_ALPHABET;
    char* humanAlphabet[ALIEN_LETTERS] = HUMAN_ALPHABET;
    // Prompt user for input word in alien language
    char word[100];
    printf("Enter word in alien language: ");
    scanf("%s", word);
    // Translate word and print result to user
    char* result = translateWord(word, alienAlphabet, humanAlphabet);
    printf("Translation: %s\n", result);
    // Free memory allocated to result string
    free(result);
    return 0;
}