//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language grammar
typedef struct {
    char *alien_word;
    char *english_translation;
} AlienLanguageGrammar;

// Define the Alien language dictionary
AlienLanguageGrammar alien_language_dictionary[] = {
    {"a", "apple"},
    {"b", "banana"},
    {"c", "cat"},
    {"d", "dog"},
    {"e", "elephant"},
    {"f", "fish"},
    {"g", "grape"},
    {"h", "horse"},
    {"i", "ice cream"},
    {"j", "juice"},
    {"k", "kite"},
    {"l", "lion"},
    {"m", "monkey"},
    {"n", "nut"},
    {"o", "orange"},
    {"p", "pineapple"},
    {"q", "queen"},
    {"r", "rabbit"},
    {"s", "snake"},
    {"t", "tiger"},
    {"u", "umbrella"},
    {"v", "violin"},
    {"w", "watermelon"},
    {"x", "x-ray"},
    {"y", "yacht"},
    {"z", "zebra"}
};

// Function to translate an Alien word to English
char *translate_alien_word(char *alien_word) {
    // Loop through the dictionary to find the matching Alien word
    for (int i = 0; i < sizeof(alien_language_dictionary) / sizeof(AlienLanguageGrammar); i++) {
        if (strcmp(alien_word, alien_language_dictionary[i].alien_word) == 0) {
            // Return the corresponding English translation
            return alien_language_dictionary[i].english_translation;
        }
    }

    // If no matching Alien word is found, return NULL
    return NULL;
}

// Function to translate an English sentence to Alien language
char *translate_english_sentence(char *english_sentence) {
    // Split the English sentence into words
    char **english_words = malloc(sizeof(char *) * strlen(english_sentence));
    int num_english_words = 0;
    char *english_word = strtok(english_sentence, " ");
    while (english_word != NULL) {
        english_words[num_english_words++] = english_word;
        english_word = strtok(NULL, " ");
    }

    // Translate each English word to Alien language
    char **alien_words = malloc(sizeof(char *) * num_english_words);
    for (int i = 0; i < num_english_words; i++) {
        alien_words[i] = translate_alien_word(english_words[i]);
    }

    // Join the Alien words into a sentence
    char *alien_sentence = malloc(sizeof(char) * 100);
    alien_sentence[0] = '\0';
    for (int i = 0; i < num_english_words; i++) {
        strcat(alien_sentence, alien_words[i]);
        strcat(alien_sentence, " ");
    }

    // Free the allocated memory
    free(english_words);
    free(alien_words);

    // Return the Alien sentence
    return alien_sentence;
}

int main() {
    // Get the Alien word or English sentence from the user
    char input[100];
    printf("Enter an Alien word or English sentence: ");
    gets(input);

    // Check if the input is an Alien word or English sentence
    if (strlen(input) == 1) {
        // Translate the Alien word to English
        char *english_translation = translate_alien_word(input);
        printf("English translation: %s\n", english_translation);
    } else {
        // Translate the English sentence to Alien language
        char *alien_translation = translate_english_sentence(input);
        printf("Alien translation: %s\n", alien_translation);
    }

    return 0;
}