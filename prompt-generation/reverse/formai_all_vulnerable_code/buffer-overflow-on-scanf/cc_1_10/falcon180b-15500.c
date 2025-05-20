//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "secret_key"

// Function to encrypt the message
void encrypt(char* message, int length) {
    int i = 0;
    int j = 0;
    char encrypted_message[length];

    // Loop through each character in the message
    while (message[i]!= '\0') {
        // Get the ASCII value of the character
        int ascii_value = message[i];

        // XOR the ASCII value with the encryption key
        ascii_value ^= KEY[j];

        // Add the encrypted ASCII value to the encrypted message
        encrypted_message[i] = ascii_value;

        // Increment the index for the encryption key
        j = (j + 1) % strlen(KEY);

        // Increment the index for the message
        i++;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* message, int length) {
    int i = 0;
    int j = 0;
    char decrypted_message[length];

    // Loop through each character in the message
    while (message[i]!= '\0') {
        // Get the ASCII value of the character
        int ascii_value = message[i];

        // XOR the ASCII value with the encryption key
        ascii_value ^= KEY[j];

        // Add the decrypted ASCII value to the decrypted message
        decrypted_message[i] = ascii_value;

        // Increment the index for the encryption key
        j = (j + 1) % strlen(KEY);

        // Increment the index for the message
        i++;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    char message[200];

    // Get the message from the user
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, strlen(message));

    // Decrypt the encrypted message
    decrypt(message, strlen(message));

    return 0;
}