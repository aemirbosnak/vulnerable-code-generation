//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

// Function to check if a character is a letter
int is_letter(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to shift a character by a given amount
char shift_char(char c, int amount) {
    if (is_letter(c)) {
        if (isupper(c)) {
            return (char) ((int) c + amount - 65);
        } else {
            return (char) ((int) c + amount - 97);
        }
    } else {
        return c;
    }
}

// Function to encrypt a string using a given key
void encrypt(char* text, char* key) {
    int i, j, key_length = strlen(key);
    char encrypted_text[MAX_TEXT_LENGTH];
    strcpy(encrypted_text, text);

    // Apply the key to each character in the text
    for (i = 0; i < strlen(text); i++) {
        if (is_letter(text[i])) {
            encrypted_text[i] = shift_char(text[i], key_length % 26);
        }
    }

    printf("Encrypted text: %s\n", encrypted_text);
}

// Function to decrypt a string using a given key
void decrypt(char* text, char* key) {
    int i, j, key_length = strlen(key);
    char decrypted_text[MAX_TEXT_LENGTH];
    strcpy(decrypted_text, text);

    // Apply the key to each character in the text
    for (i = 0; i < strlen(text); i++) {
        if (is_letter(text[i])) {
            decrypted_text[i] = shift_char(text[i], 26 - (key_length % 26));
        }
    }

    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the text to encrypt/decrypt
    printf("Enter the text to encrypt/decrypt: ");
    scanf("%s", text);

    // Get the encryption/decryption key
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Encrypt the text
    encrypt(text, key);

    // Decrypt the encrypted text
    decrypt(text, key);

    return 0;
}