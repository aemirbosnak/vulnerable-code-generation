//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 20

// Alien language dictionary
char alien_dict[26][MAX_WORD_LENGTH] = {
    "abloo", "blee", "cloo", "dloo", "eloo",
    "floo", "gloo", "hloo", "iloo", "jloo",
    "kloo", "lloo", "mloo", "nloo", "aloo",
    "ploo", "qloo", "rloo", "sloo", "tloo",
    "uloo", "vloo", "wloo", "xloo", "yloo",
    "zloo"
};

// Function to translate a word from English to Alien
void translate_to_alien(char *english_word, char *alien_word) {
    int len = strlen(english_word);

    for (int i = 0; i < len; i++) {
        char letter = english_word[i];
        int index = letter - 'a';

        strcpy(alien_word + (i * MAX_WORD_LENGTH), alien_dict[index]);
    }
}

// Function to translate a word from Alien to English
void translate_to_english(char *alien_word, char *english_word) {
    int len = strlen(alien_word);

    for (int i = 0; i < len; i++) {
        char *word = alien_word + (i * MAX_WORD_LENGTH);

        for (int j = 0; j < 26; j++) {
            if (strcmp(word, alien_dict[j]) == 0) {
                english_word[i] = j + 'a';
                break;
            }
        }
    }
}

int main() {
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH * 26];

    printf("Enter an English word: ");
    scanf("%s", english_word);

    // Translate the word to Alien
    translate_to_alien(english_word, alien_word);

    printf("Alien word: %s\n", alien_word);

    // Translate the word back to English
    translate_to_english(alien_word, english_word);

    printf("English word: %s\n", english_word);

    return 0;
}