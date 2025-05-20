//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the Vigenere cipher
char key[] = "HELLOWORLD";

// Function to encrypt a string using the Vigenere cipher
char *encryptVigenere(char *plaintext) {
    int keylen = strlen(key);
    int plaintextlen = strlen(plaintext);
    char *ciphertext = malloc(plaintextlen + 1);
    int keyIndex = 0;
    for (int i = 0; i < plaintextlen; i++) {
        // Convert plaintext character to uppercase
        char c = plaintext[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        // Encrypt character using Vigenere cipher
        ciphertext[i] = ((c + key[keyIndex]) % 26) + 'A';
        keyIndex = (keyIndex + 1) % keylen;
    }
    ciphertext[plaintextlen] = '\0';
    return ciphertext;
}

// Function to decrypt a string using the Vigenere cipher
char *decryptVigenere(char *ciphertext) {
    int keylen = strlen(key);
    int ciphertextlen = strlen(ciphertext);
    char *plaintext = malloc(ciphertextlen + 1);
    int keyIndex = 0;
    for (int i = 0; i < ciphertextlen; i++) {
        // Convert ciphertext character to uppercase
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        // Decrypt character using Vigenere cipher
        plaintext[i] = ((c - key[keyIndex]) % 26) + 'A';
        keyIndex = (keyIndex + 1) % keylen;
    }
    plaintext[ciphertextlen] = '\0';
    return plaintext;
}

// Main function
int main() {
    // Get plaintext from the user
    char plaintext[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Encrypt plaintext using Vigenere cipher
    char *ciphertext = encryptVigenere(plaintext);

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext using Vigenere cipher
    char *decrypted = decryptVigenere(ciphertext);

    // Print decrypted text
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}