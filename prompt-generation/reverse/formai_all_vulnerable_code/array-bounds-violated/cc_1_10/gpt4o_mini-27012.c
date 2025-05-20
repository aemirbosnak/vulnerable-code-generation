//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define maximum length for input strings
#define MAX_LENGTH 256

// Alien language mappings
typedef struct {
    char* english_word;
    char* alien_word;
} Translation;

// Sample translations
Translation dictionary[] = {
    {"hello", "gralux"},
    {"world", "thomara"},
    {"friend", "zorthax"},
    {"alien", "kivena"},
    {"language", "farqesh"},
    {"computer", "blignok"},
    {"program", "xalotul"},
    {"secret", "vortune"},
    {"space", "klinthar"},
    {"universe", "xylam"}
};

// Function to find the alien word for a given English word
char* translate_to_alien(char* english) {
    size_t dict_size = sizeof(dictionary) / sizeof(Translation);
    for (size_t i = 0; i < dict_size; ++i) {
        if (strcmp(english, dictionary[i].english_word) == 0) {
            return dictionary[i].alien_word;
        }
    }
    return NULL;  // Return NULL if not found
}

// Function to translate a sentence to alien language
void translate_sentence(char* sentence) {
    char* word = strtok(sentence, " ");
    char translation[MAX_LENGTH] = "";

    while (word != NULL) {
        char* alien_word = translate_to_alien(word);
        if (alien_word != NULL) {
            strcat(translation, alien_word);
            strcat(translation, " ");
        } else {
            // If no translation is found, keep the original word
            strcat(translation, word);
            strcat(translation, " ");
        }
        word = strtok(NULL, " ");
    }

    // Remove trailing space and print the translation
    translation[strlen(translation) - 1] = '\0';
    printf("Translation to Alien Language: %s\n", translation);
}

// Function to get user input
void get_user_input(char* buffer, size_t size) {
    printf("Enter a sentence in English (max %d characters): ", (int)(size - 1));
    fgets(buffer, size, stdin);
    // Remove newline character
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

// Main function
int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Alien Language Translator!\n");
    printf("This program translates common English words into a creative alien language.\n\n");

    get_user_input(input, sizeof(input));

    translate_sentence(input);

    printf("\nThank you for using the Alien Language Translator!\n");
    return 0;
}