//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
#define ALIEN_DICTIONARY_SIZE 10
char *alien_dictionary[ALIEN_DICTIONARY_SIZE] = {"Zorblatt", "Flargle", "Gronk", "Snarf", "Gleep", "Ploink", "Fizzbin", "Mungo", "Blitz", "Kaboom"};

// Function to translate English to Alien
void translate_to_alien(char *english_sentence) {
    int i = 0;
    while (english_sentence[i]!= '\0') {
        if (english_sentence[i] >= 'a' && english_sentence[i] <= 'z') {
            english_sentence[i] = alien_dictionary[english_sentence[i] - 'a'][0];
        }
        i++;
    }
}

// Function to translate Alien to English
void translate_to_english(char *alien_sentence) {
    int i = 0;
    while (alien_sentence[i]!= '\0') {
        for (int j = 0; j < ALIEN_DICTIONARY_SIZE; j++) {
            if (alien_dictionary[j][0] == alien_sentence[i]) {
                alien_sentence[i] = 'a' + j;
                break;
            }
        }
        i++;
    }
}

// Main function
int main() {
    char english_sentence[100];
    char alien_sentence[100];

    // Get English sentence from user
    printf("Enter an English sentence: ");
    scanf("%s", english_sentence);

    // Translate English to Alien
    translate_to_alien(english_sentence);

    // Print the translated Alien sentence
    printf("Alien: %s\n", english_sentence);

    // Translate Alien back to English
    translate_to_english(english_sentence);

    // Print the translated English sentence
    printf("English: %s\n", alien_sentence);

    return 0;
}