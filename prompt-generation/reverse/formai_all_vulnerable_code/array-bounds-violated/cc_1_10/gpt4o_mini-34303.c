//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_LENGTH 256

// Function to convert English letters to Alien language symbols
char translate_to_alien(char *input) {
    // A simple mapping of vowels and consonants to alien symbols
    char mapping[5] = {'@', '#', '&', '!', '*'};
    char response[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    char result[MAX_LENGTH] = {0};
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char current_char = input[i];

        // Check if the character is an uppercase letter
        if (current_char >= 'A' && current_char <= 'Z') {
            result[index++] = mapping[current_char - 'A' % 5]; // Mapping based on mod 5
        }
        // Check if the character is a lowercase letter
        else if (current_char >= 'a' && current_char <= 'z') {
            result[index++] = mapping[current_char - 'a' % 5]; // Mapping based on mod 5
        }
        // If it's not an alphabetic character, just copy it
        else {
            result[index++] = current_char; 
        }
    }
    result[index] = '\0';

    printf("Translated to Alien Language: %s\n", result);
    return *result; // For demonstration purposes
}

void alien_message_interaction() {
    char input[MAX_LENGTH];

    printf("Welcome to the Alien Language Translator\n");
    printf("Please enter a message to translate (or type 'exit' to quit):\n");

    while (1) {
        fgets(input, MAX_LENGTH, stdin);
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Alien Language Translator. Goodbye!\n");
            break;
        }

        // Translate the input string and display the result
        translate_to_alien(input);
    }
}

int main() {
    alien_message_interaction();

    return 0;
}