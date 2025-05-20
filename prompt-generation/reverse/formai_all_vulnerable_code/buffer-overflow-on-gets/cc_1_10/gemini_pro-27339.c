//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Declare a function that performs encryption.
void encrypt(char *plaintext, char *key);

// Declare a function that performs decryption.
void decrypt(char *ciphertext, char *key);

// Main function
int main() {
    // Declare variables to store the plaintext, ciphertext, and key.
    char plaintext[100], ciphertext[100], key[100];

    // Get the plaintext from the user.
    printf("Enter the plaintext: ");
    gets(plaintext);

    // Get the key from the user.
    printf("Enter the key: ");
    gets(key);

    // Encrypt the plaintext using the key.
    encrypt(plaintext, key);

    // Print the ciphertext.
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext using the key.
    decrypt(ciphertext, key);

    // Print the decrypted plaintext.
    printf("The decrypted plaintext is: %s\n", plaintext);

    return 0;
}

// Function to perform encryption.
void encrypt(char *plaintext, char *key) {
    int i, j, keylen, plaintextlen;

    // Get the length of the key.
    keylen = strlen(key);

    // Get the length of the plaintext.
    plaintextlen = strlen(plaintext);

    // XOR the plaintext with the key.
    for (i = 0, j = 0; i < plaintextlen; i++, j++) {
        if (j == keylen) {
            j = 0;
        }
        plaintext[i] ^= key[j];
    }
}

// Function to perform decryption.
void decrypt(char *ciphertext, char *key) {
    int i, j, keylen, ciphertextlen;

    // Get the length of the key.
    keylen = strlen(key);

    // Get the length of the ciphertext.
    ciphertextlen = strlen(ciphertext);

    // XOR the ciphertext with the key.
    for (i = 0, j = 0; i < ciphertextlen; i++, j++) {
        if (j == keylen) {
            j = 0;
        }
        ciphertext[i] ^= key[j];
    }
}