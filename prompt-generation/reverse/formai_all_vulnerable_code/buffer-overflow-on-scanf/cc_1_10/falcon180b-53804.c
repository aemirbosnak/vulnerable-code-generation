//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 256

// Function to encrypt the given text using the given key
void encrypt(char *text, char *key) {
    int i, j, key_index = 0;
    char encrypted_text[MAX_TEXT_LENGTH];

    // Initialize the encrypted text to the given text
    strcpy(encrypted_text, text);

    // Encrypt the text using the key
    for (i = 0; i < strlen(text); i++) {
        // Convert the text and key to uppercase
        text[i] = toupper(text[i]);
        key[key_index] = toupper(key[key_index]);

        // Encrypt the current character
        if (isalpha(text[i])) {
            encrypted_text[i] = (char) (text[i] + key[key_index] - 65);
            key_index++;
            if (key_index >= strlen(key)) {
                key_index = 0;
            }
        } else {
            encrypted_text[i] = text[i];
        }
    }

    printf("Encrypted text: %s\n", encrypted_text);
}

// Function to decrypt the given encrypted text using the given key
void decrypt(char *encrypted_text, char *key) {
    int i, j, key_index = 0;
    char decrypted_text[MAX_TEXT_LENGTH];

    // Initialize the decrypted text to the given encrypted text
    strcpy(decrypted_text, encrypted_text);

    // Decrypt the text using the key
    for (i = 0; i < strlen(encrypted_text); i++) {
        // Convert the encrypted text and key to uppercase
        encrypted_text[i] = toupper(encrypted_text[i]);
        key[key_index] = toupper(key[key_index]);

        // Decrypt the current character
        if (isalpha(encrypted_text[i])) {
            decrypted_text[i] = (char) (encrypted_text[i] - key[key_index] + 65);
            key_index++;
            if (key_index >= strlen(key)) {
                key_index = 0;
            }
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
    }

    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];
    int key_length;

    // Get the text and key from the user
    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Get the key length from the user
    printf("Enter the key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &key_length);

    // Encrypt the text using the key
    encrypt(text, key);

    // Decrypt the encrypted text using the key
    decrypt(text, key);

    return 0;
}