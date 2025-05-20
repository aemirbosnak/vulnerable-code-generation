//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
/*
*  Cryptography Implementation Example Program in an Inquisitive Style
*
*  This program demonstrates a simple cryptography implementation using a Caesar Cipher.
*  It takes a message and a key as input, encrypts the message using the Caesar Cipher, and then decrypts it.
*  The Caesar Cipher is a simple substitution cipher that replaces each letter with a letter a fixed number of positions down the alphabet.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a message using the Caesar Cipher
char* encrypt(char* message, int key) {
    // Create a new string to store the encrypted message
    char* encrypted = malloc(strlen(message) + 1);
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Get the character at the current position
        char c = message[i];
        // If the character is a letter, encrypt it using the Caesar Cipher
        if (c >= 'a' && c <= 'z') {
            encrypted[i] = (c + key - 'a') % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            encrypted[i] = (c + key - 'A') % 26 + 'A';
        } else {
            // If the character is not a letter, leave it unchanged
            encrypted[i] = c;
        }
    }
    encrypted[strlen(message)] = '\0';
    return encrypted;
}

// Function to decrypt a message using the Caesar Cipher
char* decrypt(char* encrypted, int key) {
    // Create a new string to store the decrypted message
    char* message = malloc(strlen(encrypted) + 1);
    // Loop through each character in the encrypted message
    for (int i = 0; i < strlen(encrypted); i++) {
        // Get the character at the current position
        char c = encrypted[i];
        // If the character is a letter, decrypt it using the Caesar Cipher
        if (c >= 'a' && c <= 'z') {
            message[i] = (c - key - 'a') % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            message[i] = (c - key - 'A') % 26 + 'A';
        } else {
            // If the character is not a letter, leave it unchanged
            message[i] = c;
        }
    }
    message[strlen(encrypted)] = '\0';
    return message;
}

int main() {
    // Get the message and key from the user
    printf("Enter the message: ");
    char* message = malloc(100);
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    int key;
    scanf("%d", &key);

    // Encrypt the message
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    // Free memory
    free(message);
    free(encrypted);
    free(decrypted);

    return 0;
}