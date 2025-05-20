//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 256
#define KEY_LENGTH 26

// Function to generate a simple Caesar cipher encryption
void caesar_encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + shift) % KEY_LENGTH + offset;
        }
    }
}

// Function to decrypt the text using the Caesar cipher
void caesar_decrypt(char *text, int shift) {
    caesar_encrypt(text, KEY_LENGTH - shift); // Decryption is reverse of encryption
}

// Function to generate a random key for Vigenère cipher encryption
void generate_key(const char *text, const char *key, char *output) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    for (int i = 0, j = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            output[i] = key[j % key_length];
            j++;
        } else {
            output[i] = text[i]; // Non-alpha characters remain unchanged
        }
    }
    output[text_length] = '\0'; // Null-terminate the output string
}

// Function to encrypt text using Vigenère cipher
void vigenere_encrypt(char *text, const char *key) {
    char *output = (char *)malloc(MAX_TEXT_LENGTH);
    char key_generated[MAX_TEXT_LENGTH] = {0};
    generate_key(text, key, key_generated);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            char key_offset = isupper(key_generated[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + (key_generated[i] - key_offset)) % KEY_LENGTH + offset;
        }
    }
    free(output);
}

// Function to decrypt text using Vigenère cipher
void vigenere_decrypt(char *text, const char *key) {
    char *output = (char *)malloc(MAX_TEXT_LENGTH);
    char key_generated[MAX_TEXT_LENGTH] = {0};
    generate_key(text, key, key_generated);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            char key_offset = isupper(key_generated[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset - (key_generated[i] - key_offset) + KEY_LENGTH) % KEY_LENGTH + offset;
        }
    }
    free(output);
}

// Main function to demonstrate both ciphers
int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_TEXT_LENGTH];
    int shift;

    printf("Enter the text to be encrypted (max %d characters):\n", MAX_TEXT_LENGTH - 1);
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    // Caesar cipher
    printf("Enter the shift value for Caesar cipher (1-25):\n");
    scanf("%d", &shift);
    getchar(); // Consume leftover newline character

    char caesar_text[MAX_TEXT_LENGTH];
    strcpy(caesar_text, text);
    caesar_encrypt(caesar_text, shift);
    printf("Encrypted text with Caesar cipher: %s\n", caesar_text);

    caesar_decrypt(caesar_text, shift);
    printf("Decrypted text with Caesar cipher: %s\n", caesar_text);

    // Vigenère cipher
    printf("Enter the keyword for Vigenère cipher (max %d characters):\n", MAX_TEXT_LENGTH - 1);
    fgets(key, MAX_TEXT_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    char vigenere_text[MAX_TEXT_LENGTH];
    strcpy(vigenere_text, text);
    vigenere_encrypt(vigenere_text, key);
    printf("Encrypted text with Vigenère cipher: %s\n", vigenere_text);

    vigenere_decrypt(vigenere_text, key);
    printf("Decrypted text with Vigenère cipher: %s\n", vigenere_text);

    return 0;
}