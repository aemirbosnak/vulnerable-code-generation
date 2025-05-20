//Falcon-180B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the encryption function
void encrypt(char* message, int key) {
    int i, j;
    char result[100];

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Determine the ASCII value of the character
        int ascii = message[i];

        // Apply the encryption key
        ascii += key;

        // Convert the ASCII value to a character and add it to the result string
        result[i] = ascii;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", result);
}

// Define the decryption function
void decrypt(char* message, int key) {
    int i, j;
    char result[100];

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Determine the ASCII value of the character
        int ascii = message[i];

        // Apply the decryption key
        ascii -= key;

        // Convert the ASCII value to a character and add it to the result string
        result[i] = ascii;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", result);
}

// Define the main function
int main() {
    char message[100];

    // Prompt the user to enter a message to encrypt
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Prompt the user to enter an encryption key
    int key;
    printf("Enter an encryption key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}