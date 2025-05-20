//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style Alien Language Translator

// Alien language dictionary
struct alien_dict {
    char alien_char;
    char english_char;
};

// Dictionary of Alien and English characters
struct alien_dict dictionary[] = {
    {'!', 'a'},
    {'@', 'b'},
    {'#', 'c'},
    {'$', 'd'},
    {'%', 'e'},
    {'^', 'f'},
    {'&', 'g'},
    {'*', 'h'},
    {'(', 'i'},
    {')', 'j'},
    {'_', 'k'},
    {'=', 'l'},
    {'+', 'm'},
    {'-', 'n'},
    {'[', 'o'},
    {']', 'p'},
    {'{', 'q'},
    {'}', 'r'},
    {'|', 's'},
    {':', 't'},
    {';', 'u'},
    {'<', 'v'},
    {'>', 'w'},
    {'?', 'x'},
    {'/', 'y'},
    {'.', 'z'},
    {' ', ' '},
};

// Function to translate Alien text to English
char *alien_to_english(char *alien_text) {
    // Allocate memory for the translated text
    char *english_text = malloc(strlen(alien_text) + 1);

    // Translate each character in the Alien text
    for (int i = 0; i < strlen(alien_text); i++) {
        // Find the Alien character in the dictionary
        for (int j = 0; j < sizeof(dictionary) / sizeof(struct alien_dict); j++) {
            if (dictionary[j].alien_char == alien_text[i]) {
                // Replace the Alien character with the English character
                english_text[i] = dictionary[j].english_char;
                break;
            }
        }
    }

    // Null-terminate the translated text
    english_text[strlen(alien_text)] = '\0';

    // Return the translated text
    return english_text;
}

// Function to translate English text to Alien
char *english_to_alien(char *english_text) {
    // Allocate memory for the translated text
    char *alien_text = malloc(strlen(english_text) + 1);

    // Translate each character in the English text
    for (int i = 0; i < strlen(english_text); i++) {
        // Find the English character in the dictionary
        for (int j = 0; j < sizeof(dictionary) / sizeof(struct alien_dict); j++) {
            if (dictionary[j].english_char == english_text[i]) {
                // Replace the English character with the Alien character
                alien_text[i] = dictionary[j].alien_char;
                break;
            }
        }
    }

    // Null-terminate the translated text
    alien_text[strlen(english_text)] = '\0';

    // Return the translated text
    return alien_text;
}

// Main function
int main() {
    // Get the Alien text from the user
    char *alien_text = malloc(1024);
    printf("Enter the Alien text: ");
    scanf("%s", alien_text);

    // Translate the Alien text to English
    char *english_text = alien_to_english(alien_text);

    // Print the translated English text
    printf("English translation: %s\n", english_text);

    // Free the allocated memory
    free(alien_text);
    free(english_text);

    return 0;
}