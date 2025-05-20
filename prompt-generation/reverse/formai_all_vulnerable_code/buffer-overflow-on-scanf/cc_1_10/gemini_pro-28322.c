//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
struct alien_dict {
    char alien_char;
    char english_char;
};

// Create an array of Alien language characters and their corresponding English translations
struct alien_dict dictionary[] = {
    {'a', 'e'},
    {'b', 't'},
    {'c', 'a'},
    {'d', 'n'},
    {'e', 'i'},
    {'f', 'o'},
    {'g', 'u'},
    {'h', 'r'},
    {'i', 's'},
    {'j', 'l'},
    {'k', 'd'},
    {'l', 'h'},
    {'m', 'f'},
    {'n', 'g'},
    {'o', 'j'},
    {'p', 'k'},
    {'q', 'p'},
    {'r', 'y'},
    {'s', 'w'},
    {'t', 'q'},
    {'u', 'x'},
    {'v', 'z'},
    {'w', 'c'},
    {'x', 'v'},
    {'y', 'b'},
    {'z', 'm'}
};

// Function to translate an Alien language word to English
char *alien_to_english(char *alien_word) {
    int len = strlen(alien_word);
    char *english_word = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (alien_word[i] == dictionary[j].alien_char) {
                english_word[i] = dictionary[j].english_char;
            }
        }
    }
    english_word[len] = '\0';
    return english_word;
}

// Function to translate an English word to Alien language
char *english_to_alien(char *english_word) {
    int len = strlen(english_word);
    char *alien_word = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (english_word[i] == dictionary[j].english_char) {
                alien_word[i] = dictionary[j].alien_char;
            }
        }
    }
    alien_word[len] = '\0';
    return alien_word;
}

// Main function
int main() {
    // Get the Alien language word from the user
    printf("Enter an Alien language word: ");
    char alien_word[100];
    scanf("%s", alien_word);

    // Translate the Alien language word to English
    char *english_word = alien_to_english(alien_word);

    // Print the English translation
    printf("The English translation is: %s\n", english_word);

    // Get the English word from the user
    printf("Enter an English word: ");
    char english_word_input[100];
    scanf("%s", english_word_input);

    // Translate the English word to Alien language
    char *alien_word_translated = english_to_alien(english_word_input);

    // Print the Alien language translation
    printf("The Alien language translation is: %s\n", alien_word_translated);

    return 0;
}