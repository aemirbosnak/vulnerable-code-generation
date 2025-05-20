//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
#define ALIEN_DICTIONARY_SIZE 10
char *alien_dictionary[] = {
    "Zorblatt",
    "Flibberjab",
    "Gronk",
    "Snarfle",
    "Plooble",
    "Quizzik",
    "Mungo",
    "Fizzbin",
    "Blibber",
    "Droogle"
};

// Function to translate English to Alien language
void translate_to_alien(char *english_word) {
    int index = rand() % ALIEN_DICTIONARY_SIZE;
    printf("The Alien translation of '%s' is '%s'.\n", english_word, alien_dictionary[index]);
}

// Function to translate Alien to English
void translate_to_english(char *alien_word) {
    int index = 0;
    while (index < ALIEN_DICTIONARY_SIZE && strcmp(alien_dictionary[index], alien_word)!= 0) {
        index++;
    }
    if (index == ALIEN_DICTIONARY_SIZE) {
        printf("'%s' is not a valid Alien word.\n", alien_word);
    } else {
        printf("The English translation of '%s' is '%s'.\n", alien_word, alien_dictionary[index]);
    }
}

int main() {
    char input[100];

    // Example usage
    printf("Enter an English word to translate to Alien:\n");
    scanf("%s", input);
    translate_to_alien(input);

    printf("\nEnter an Alien word to translate to English:\n");
    scanf("%s", input);
    translate_to_english(input);

    return 0;
}