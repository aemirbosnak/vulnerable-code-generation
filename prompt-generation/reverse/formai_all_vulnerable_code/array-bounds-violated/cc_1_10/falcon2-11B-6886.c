//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert alien language to English
void translate_alien_language(char* input_string) {
    int i, j, k;
    char output_string[100];
    
    // Convert alien language to English
    for (i = 0; i < strlen(input_string); i++) {
        if (isalpha(input_string[i])) {
            if (islower(input_string[i])) {
                output_string[j++] = toupper(input_string[i]);
            } else {
                output_string[j++] = tolower(input_string[i]);
            }
        } else {
            output_string[j++] = input_string[i];
        }
    }
    output_string[j] = '\0';
    
    // Print translated English string
    printf("English translation: %s\n", output_string);
}

// Function to convert English to alien language
void translate_english_to_alien_language(char* input_string) {
    int i, j, k;
    char output_string[100];
    
    // Convert English to alien language
    for (i = 0; i < strlen(input_string); i++) {
        if (isalpha(input_string[i])) {
            if (islower(input_string[i])) {
                output_string[j++] = toupper(input_string[i]);
            } else {
                output_string[j++] = tolower(input_string[i]);
            }
        } else {
            output_string[j++] = input_string[i];
        }
    }
    output_string[j] = '\0';
    
    // Print translated alien language string
    printf("Alien language translation: %s\n", output_string);
}

int main() {
    char input_string[100];
    
    // Get input string from user
    printf("Enter a string in English: ");
    fgets(input_string, 100, stdin);
    
    // Translate English to alien language
    translate_english_to_alien_language(input_string);
    
    // Get input string from user
    printf("Enter a string in alien language: ");
    fgets(input_string, 100, stdin);
    
    // Translate alien language to English
    translate_alien_language(input_string);
    
    return 0;
}