//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the given key
void encrypt(char *message, char *key) {
    int i, j, k;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    // Initialize the encrypted message to empty
    memset(encrypted_message, '\0', strlen(message));

    // Loop through each character in the message
    for (i = 0; i < strlen(message); i++) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Convert the key to uppercase
        key[i % strlen(key)] = toupper(key[i % strlen(key)]);

        // Encrypt the character using the key
        encrypted_message[i] = message[i] ^ key[i % strlen(key)];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the given key
void decrypt(char *encrypted_message, char *key) {
    int i, j, k;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Initialize the decrypted message to empty
    memset(decrypted_message, '\0', strlen(encrypted_message));

    // Loop through each character in the encrypted message
    for (i = 0; i < strlen(encrypted_message); i++) {
        // Convert the character to uppercase
        encrypted_message[i] = toupper(encrypted_message[i]);

        // Convert the key to uppercase
        key[i % strlen(key)] = toupper(key[i % strlen(key)]);

        // Decrypt the character using the key
        decrypted_message[i] = encrypted_message[i] ^ key[i % strlen(key)];
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message using the given key
    encrypt(message, key);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);

    return 0;
}