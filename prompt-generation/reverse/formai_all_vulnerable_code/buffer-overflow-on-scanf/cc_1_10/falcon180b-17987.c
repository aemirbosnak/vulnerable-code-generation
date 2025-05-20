//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Define the alphabet used for encryption
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Define the alphabet used for decryption
#define DECRYPT_ALPHABET "ZYXWVUTSRQPONMLKJIHGFEDCBA"

// Function to encrypt the message
void encrypt(char *message) {
    int i = 0;
    char encrypted_message[strlen(message)];

    // Loop through each character in the message
    while (message[i]) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Find the index of the letter in the alphabet
            int index = message[i] - 'A';

            // Encrypt the letter using the alphabet
            encrypted_message[i] = ALPHABET[index];
        } else {
            // Copy non-letter characters as is
            encrypted_message[i] = message[i];
        }

        // Move to the next character
        i++;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char *message) {
    int i = 0;
    char decrypted_message[strlen(message)];

    // Loop through each character in the message
    while (message[i]) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Find the index of the letter in the decryption alphabet
            int index = DECRYPT_ALPHABET[message[i] - 'A'];

            // Decrypt the letter using the decryption alphabet
            decrypted_message[i] = index + 'A';
        } else {
            // Copy non-letter characters as is
            decrypted_message[i] = message[i];
        }

        // Move to the next character
        i++;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    // Prompt the user for a message to encrypt
    printf("Enter a message to encrypt: ");
    char message[100];
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    char encrypted_message[100];
    strcpy(encrypted_message, message);
    decrypt(encrypted_message);

    return 0;
}