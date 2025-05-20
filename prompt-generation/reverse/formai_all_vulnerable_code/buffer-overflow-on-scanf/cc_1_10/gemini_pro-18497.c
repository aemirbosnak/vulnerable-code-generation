//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cat language vocabulary
const char *cat_vocabulary[] = {
    "meow", "purr", "hiss", "growl", "yowl", "chirp", "trill", "chatter", "mew", "squeak"
};

// Define the English language vocabulary
const char *english_vocabulary[] = {
    "hello", "thank you", "goodbye", "yes", "no", "please", "sorry", "excuse me", "I love you", "goodbye"
};

// Translate a cat language word to English
char *cat_to_english(const char *cat_word) {
    for (int i = 0; i < sizeof(cat_vocabulary) / sizeof(char *); i++) {
        if (strcmp(cat_word, cat_vocabulary[i]) == 0) {
            return (char *)english_vocabulary[i];
        }
    }

    return NULL;
}

// Translate an English word to cat language
char *english_to_cat(const char *english_word) {
    for (int i = 0; i < sizeof(english_vocabulary) / sizeof(char *); i++) {
        if (strcmp(english_word, english_vocabulary[i]) == 0) {
            return (char *)cat_vocabulary[i];
        }
    }

    return NULL;
}

// Main function
int main() {
    // Get the cat language input from the user
    char cat_input[100];
    printf("Enter a cat language word: ");
    scanf("%s", cat_input);

    // Translate the cat language input to English
    char *english_output = cat_to_english(cat_input);

    // Print the English translation
    printf("English translation: %s\n", english_output);

    // Get the English language input from the user
    char english_input[100];
    printf("Enter an English word: ");
    scanf("%s", english_input);

    // Translate the English language input to cat language
    char *cat_output = english_to_cat(english_input);

    // Print the cat language translation
    printf("Cat language translation: %s\n", cat_output);

    return 0;
}