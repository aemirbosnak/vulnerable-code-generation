//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
const char *alien_lang[26] = {
    "Aeb", "Bof", "Cof", "Doh", "Eef", "Fef", "Goh", "Hof", "Iof", "Jof",
    "Koh", "Loh", "Mof", "Nof", "Oof", "Pof", "Qof", "Rof", "Sof", "Tof",
    "Uof", "Vof", "Wof", "Xof", "Yof", "Zof"
};

// Function to translate a word from English to Alien
char *translate_to_alien(char *word) {
    // Allocate memory for the translated word
    char *translated_word = (char *)malloc(strlen(word) * 3);

    // Loop through each character in the word
    int i;
    for (i = 0; i < strlen(word); i++) {
        // Convert the character to uppercase
        word[i] = toupper(word[i]);

        // Find the index of the character in the alien language dictionary
        int index = word[i] - 'A';

        // Append the alien language translation to the translated word
        strcat(translated_word, alien_lang[index]);
    }

    // Return the translated word
    return translated_word;
}

// Function to translate a word from Alien to English
char *translate_to_english(char *word) {
    // Allocate memory for the translated word
    char *translated_word = (char *)malloc(strlen(word) / 3);

    // Loop through each character in the word
    int i;
    for (i = 0; i < strlen(word); i += 3) {
        // Find the index of the alien language translation in the dictionary
        int index;
        for (index = 0; index < 26; index++) {
            if (strcmp(word + i, alien_lang[index]) == 0) {
                break;
            }
        }

        // Convert the index to a character
        char character = index + 'A';

        // Append the character to the translated word
        translated_word[i / 3] = character;
    }

    // Return the translated word
    return translated_word;
}

// Main function
int main() {
    // Get the word to be translated
    char word[100];
    printf("Enter the word to be translated: ");
    scanf("%s", word);

    // Translate the word to Alien
    char *translated_to_alien = translate_to_alien(word);

    // Print the translated word
    printf("Translated to Alien: %s\n", translated_to_alien);

    // Free the memory allocated for the translated word
    free(translated_to_alien);

    // Translate the word to English
    char *translated_to_english = translate_to_english(translated_to_alien);

    // Print the translated word
    printf("Translated to English: %s\n", translated_to_english);

    // Free the memory allocated for the translated word
    free(translated_to_english);

    return 0;
}