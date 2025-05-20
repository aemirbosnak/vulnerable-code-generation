//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
/*
 * Cryptography Implementation Example Program
 *
 * This program implements a simple encryption and decryption algorithm using
 * a Caesar cipher. The Caesar cipher is a classic substitution cipher that
 * replaces each letter with a letter a fixed number of positions down the
 * alphabet. In this example, we use a shift of 3.
 *
 * This program can be used to encrypt and decrypt messages of arbitrary
 * length.
 */

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

/*
 * Encrypts a message using a Caesar cipher with a shift of 3.
 *
 * message: the message to encrypt
 * length: the length of the message
 */
void encrypt(char *message, int length) {
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] - 'A' + 3) % ALPHABET_SIZE) + 'A');
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] - 'a' + 3) % ALPHABET_SIZE) + 'a');
        }
    }
}

/*
 * Decrypts a message using a Caesar cipher with a shift of 3.
 *
 * message: the message to decrypt
 * length: the length of the message
 */
void decrypt(char *message, int length) {
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((message[i] - 'A' - 3) % ALPHABET_SIZE) + 'A');
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((message[i] - 'a' - 3) % ALPHABET_SIZE) + 'a');
        }
    }
}

int main() {
    char message[100];
    int length;

    // Get the message to encrypt/decrypt
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the length of the message
    length = strlen(message);

    // Encrypt the message
    encrypt(message, length);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, length);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}