//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
/*
 * Encryption program using a simple substitution cipher
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the substitution cipher
char cipher[26] = "abcdefghijklmnopqrstuvwxyz";

// Function to encrypt a message
char* encrypt(char* message) {
    char* encrypted = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = cipher[(message[i] - 'a') % 26];
    }
    return encrypted;
}

// Function to decrypt a message
char* decrypt(char* message) {
    char* decrypted = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        decrypted[i] = cipher[(message[i] - 'a') % 26];
    }
    return decrypted;
}

int main() {
    // Prompt the user for a message to encrypt
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Encrypt the message
    char* encrypted = encrypt(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    char* decrypted = decrypt(encrypted);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    // Free the memory allocated for the encrypted and decrypted messages
    free(encrypted);
    free(decrypted);

    return 0;
}