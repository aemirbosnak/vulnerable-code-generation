//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
/*
 * Cryptography Implementation Example Program
 *
 * This program implements a simple cryptography algorithm that encrypts and decrypts
 * messages using a substitution cipher. The algorithm is based on the Caesar cipher,
 * which replaces each letter in the plaintext with a letter that is a fixed number
 * of positions down the alphabet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a substitution cipher
void encrypt(char* message, int shift) {
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // If the character is a letter, encrypt it
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt a message using a substitution cipher
void decrypt(char* message, int shift) {
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // If the character is a letter, decrypt it
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - shift) % 26 + 'A';
        }
    }
}

int main() {
    // Define the message to encrypt and the shift value
    char* message = "Hello, World!";
    int shift = 3;

    // Encrypt the message
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}