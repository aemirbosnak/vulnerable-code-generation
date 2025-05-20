//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of letters in the alien alphabet
#define ALIEN_ALPHABET_COUNT 26

// Define the maximum length of a word in the alien language
#define ALIEN_WORD_MAX_LENGTH 100

// Define the translation table from alien letters to English letters
char alien_to_english_translation_table[ALIEN_ALPHABET_COUNT] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

// Define the translation table from English letters to alien letters
char english_to_alien_translation_table[ALIEN_ALPHABET_COUNT] = {
    'e', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'f', 'g', 'h', 'i'
};

// Translate an alien word to English
void alien_to_english(char *alien_word) {
    int i;
    for (i = 0; alien_word[i] != '\0'; i++) {
        alien_word[i] = alien_to_english_translation_table[alien_word[i] - 'a'];
    }
}

// Translate an English word to alien
void english_to_alien(char *english_word) {
    int i;
    for (i = 0; english_word[i] != '\0'; i++) {
        english_word[i] = english_to_alien_translation_table[english_word[i] - 'a'];
    }
}

// Encrypt a message using the alien language
void encrypt_message(char *message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            english_to_alien(message + i);
        }
    }
}

// Decrypt a message using the alien language
void decrypt_message(char *message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            alien_to_english(message + i);
        }
    }
}

// Main function
int main() {
    // Get the message to be translated
    char message[1024];
    printf("Enter the message to be translated: ");
    gets(message);

    // Encrypt the message
    encrypt_message(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt_message(message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}