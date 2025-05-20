//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "at", "bc", "de", "fg", "hi", "jk", "lm", "no", "pq", "rs",
    "tu", "vw", "xz", "Aa", "Bb", "Cc", "Dd", "Ee", "Ff", "Gg",
    "Hh", "Ii", "Jj", "Kk", "Ll", "Mm", "Nn", "Oo", "Pp", "Qq",
    "Rr", "Ss", "Tt", "Uu", "Vv", "Ww", "Xx", "Yy", "Zz"
};

// Function to translate a word from English to Alien
char *english_to_alien(const char *word)
{
    // Allocate memory for the translated word
    char *alien_word = malloc(strlen(word) + 1);
    if (alien_word == NULL) {
        return NULL;
    }

    // Translate the word one character at a time
    int i;
    for (i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (index < 0 || index >= sizeof(alien_dict) / sizeof(alien_dict[0])) {
            alien_word[i] = word[i];
        } else {
            alien_word[i] = alien_dict[index][0];
        }
    }

    // Terminate the translated word with a null character
    alien_word[strlen(word)] = '\0';

    // Return the translated word
    return alien_word;
}

// Function to translate a word from Alien to English
char *alien_to_english(const char *word)
{
    // Allocate memory for the translated word
    char *english_word = malloc(strlen(word) + 1);
    if (english_word == NULL) {
        return NULL;
    }

    // Translate the word one character at a time
    int i;
    for (i = 0; i < strlen(word); i++) {
        int index;
        for (index = 0; index < sizeof(alien_dict) / sizeof(alien_dict[0]); index++) {
            if (alien_dict[index][0] == word[i]) {
                break;
            }
        }
        if (index >= sizeof(alien_dict) / sizeof(alien_dict[0])) {
            english_word[i] = word[i];
        } else {
            english_word[i] = 'a' + index;
        }
    }

    // Terminate the translated word with a null character
    english_word[strlen(word)] = '\0';

    // Return the translated word
    return english_word;
}

// Main function
int main()
{
    // Get the word to be translated from the user
    char word[100];
    printf("Enter the word you want to translate: ");
    scanf("%s", word);

    // Translate the word from English to Alien
    char *alien_word = english_to_alien(word);
    if (alien_word == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Print the translated word
    printf("The word in Alien is: %s\n", alien_word);

    // Translate the word from Alien to English
    char *english_word = alien_to_english(alien_word);
    if (english_word == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Print the translated word
    printf("The word in English is: %s\n", english_word);

    // Free the memory allocated for the translated words
    free(alien_word);
    free(english_word);

    return EXIT_SUCCESS;
}