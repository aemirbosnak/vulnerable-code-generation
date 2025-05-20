//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the message and key
#define MAX_LENGTH 100

// Function to encrypt the message using the key
void encrypt(char message[], char key[]) {
    int i, j;
    char encrypted_message[MAX_LENGTH];

    // Copy the message into the encrypted message array
    strcpy(encrypted_message, message);

    // Encrypt the message using the key
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ key[j];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char encrypted_message[], char key[]) {
    int i, j;
    char decrypted_message[MAX_LENGTH];

    // Copy the encrypted message into the decrypted message array
    strcpy(decrypted_message, encrypted_message);

    // Decrypt the message using the key
    for (i = 0, j = 0; i < strlen(encrypted_message); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_LENGTH], key[MAX_LENGTH];

    // Get the message and key from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);

    return 0;
}