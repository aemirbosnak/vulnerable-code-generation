//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using the Caesar cipher
void encrypt(char message[], int key) {
    int i = 0;
    int len = strlen(message);

    // Loop through each character in the message
    for (i = 0; i < len; i++) {
        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Convert the letter to uppercase
            message[i] = toupper(message[i]);

            // Encrypt the letter using the key
            if (isalpha(message[i])) {
                if (isupper(message[i])) {
                    message[i] = 'A' + ((message[i] - 'A' + key) % 26);
                } else {
                    message[i] = 'a' + ((message[i] - 'a' + key) % 26);
                }
            }
        }
    }
}

// Function to decrypt the encrypted message using the Caesar cipher
void decrypt(char message[], int key) {
    int i = 0;
    int len = strlen(message);

    // Loop through each character in the message
    for (i = 0; i < len; i++) {
        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Convert the letter to uppercase
            message[i] = toupper(message[i]);

            // Decrypt the letter using the key
            if (isalpha(message[i])) {
                if (isupper(message[i])) {
                    message[i] = 'A' + ((message[i] - 'A' - key + 26) % 26);
                } else {
                    message[i] = 'a' + ((message[i] - 'a' - key + 26) % 26);
                }
            }
        }
    }
}

int main() {
    char message[1000];
    int key;

    // Prompt the user to enter the message to be encrypted/decrypted
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    // Prompt the user to enter the key
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message using the Caesar cipher
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using the Caesar cipher
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}