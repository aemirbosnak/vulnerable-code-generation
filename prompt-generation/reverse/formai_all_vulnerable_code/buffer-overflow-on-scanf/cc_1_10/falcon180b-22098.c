//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the key
#define KEY "MySecretKey"

// Define the encryption function
void encrypt(char* message) {
    int i, j, n = strlen(message);
    char key = KEY[0];

    // Loop through each character in the message
    for (i = 0; i < n; i++) {
        // Get the ASCII value of the character
        int ascii = message[i];

        // Encrypt the character by adding the key
        ascii += key;

        // Wrap around if the ASCII value goes out of range
        if (ascii > 'z') {
            ascii = 'a';
        } else if (ascii < 'a') {
            ascii = 'z';
        }

        // Add the encrypted character to the encrypted message
        message[i] = ascii;
    }
}

// Define the decryption function
void decrypt(char* message) {
    int i, j, n = strlen(message);
    char key = KEY[0];

    // Loop through each character in the message
    for (i = 0; i < n; i++) {
        // Get the ASCII value of the character
        int ascii = message[i];

        // Decrypt the character by subtracting the key
        ascii -= key;

        // Wrap around if the ASCII value goes out of range
        if (ascii > 'z') {
            ascii = 'a';
        } else if (ascii < 'a') {
            ascii = 'z';
        }

        // Add the decrypted character to the decrypted message
        message[i] = ascii;
    }
}

// Define the main function
int main() {
    char message[100];
    char encrypted[100];
    char decrypted[100];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);
    strcpy(encrypted, message);

    // Decrypt the encrypted message
    decrypt(encrypted);
    strcpy(decrypted, encrypted);

    // Print the original and decrypted messages
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}