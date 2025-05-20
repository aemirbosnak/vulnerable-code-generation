//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language alphabet and its corresponding English alphabet
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char english_alphabet[] = "bcd1efg42hijklmn567opqrstuvwxyz";

// Functions to translate from English to Alien and vice versa
char *english_to_alien(char *english) {
    int i;
    char *alien = malloc(strlen(english) + 1);
    for (i = 0; english[i] != '\0'; i++) {
        alien[i] = english_alphabet[strchr(alien_alphabet, english[i]) - alien_alphabet];
    }
    alien[i] = '\0';
    return alien;
}

char *alien_to_english(char *alien) {
    int i;
    char *english = malloc(strlen(alien) + 1);
    for (i = 0; alien[i] != '\0'; i++) {
        english[i] = alien_alphabet[strchr(english_alphabet, alien[i]) - english_alphabet];
    }
    english[i] = '\0';
    return english;
}

// Main function to get user input and translate it
int main() {
    char input[100];
    int choice;

    // Get user input
    printf("Enter the text to be translated:\n");
    gets(input);

    // Get user choice (English to Alien or Alien to English)
    printf("Enter your choice:\n1. English to Alien\n2. Alien to English\n");
    scanf("%d", &choice);

    // Translate the text based on user choice
    char *translated_text;
    switch (choice) {
        case 1:
            translated_text = english_to_alien(input);
            break;
        case 2:
            translated_text = alien_to_english(input);
            break;
        default:
            printf("Invalid choice");
            return 1;
    }

    // Print the translated text
    printf("Translated text: %s\n", translated_text);
    free(translated_text);

    return 0;
}