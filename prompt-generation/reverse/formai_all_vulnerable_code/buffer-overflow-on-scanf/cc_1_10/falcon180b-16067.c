//Falcon-180B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int i, j;
    char cipher[strlen(message)]; // Initialize the cipher array with the same length as the message
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz"; // Initialize the alphabet array

    // Loop through each character in the message
    for (i = 0; i < strlen(message); i++) {
        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Get the index of the letter in the alphabet array
            int index = message[i] - 'a';

            // Shift the index by the key
            index = (index + key) % 26;

            // Get the letter from the alphabet array
            char letter = alphabet[index];

            // Add the letter to the cipher array
            cipher[i] = letter;
        } else {
            // If the character is not a letter, leave it as it is
            cipher[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", cipher);
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int i, j;
    char plaintext[strlen(message)]; // Initialize the plaintext array with the same length as the message
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz"; // Initialize the alphabet array

    // Loop through each character in the message
    for (i = 0; i < strlen(message); i++) {
        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Get the index of the letter in the alphabet array
            int index = message[i] - 'a';

            // Shift the index by the key in the opposite direction
            index = (26 - index + key) % 26;

            // Get the letter from the alphabet array
            char letter = alphabet[index];

            // Add the letter to the plaintext array
            plaintext[i] = letter;
        } else {
            // If the character is not a letter, leave it as it is
            plaintext[i] = message[i];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", plaintext);
}

// Main function
int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}