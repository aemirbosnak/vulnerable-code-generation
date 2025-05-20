//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int i, j, k, n;
    char encrypted_message[MAX_KEY_LENGTH];

    // Copy the message into the encrypted_message array
    strcpy(encrypted_message, message);

    // Loop through the message and key, XORing each character
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        encrypted_message[i] ^= key[j];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char* encrypted_message, char* key) {
    int i, j, k, n;
    char decrypted_message[MAX_KEY_LENGTH];

    // Copy the encrypted message into the decrypted_message array
    strcpy(decrypted_message, encrypted_message);

    // Loop through the encrypted message and key, XORing each character
    for (i = 0, j = 0; i < strlen(encrypted_message); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        decrypted_message[i] ^= key[j];
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}