//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 32

// Function to encrypt the given message using the key
void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[strlen(message)];

    // Initialize the encrypted message to empty
    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = '\0';
    }

    // Encrypt the message using the key
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < strlen(key); j++) {
            encrypted_message[i] = message[i] ^ key[j];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the given message using the key
void decrypt(char *encrypted_message, char *key) {
    int i, j;
    char decrypted_message[strlen(encrypted_message)];

    // Initialize the decrypted message to empty
    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = '\0';
    }

    // Decrypt the message using the key
    for (i = 0; i < strlen(encrypted_message); i++) {
        for (j = 0; j < strlen(key); j++) {
            decrypted_message[i] = encrypted_message[i] ^ key[j];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the encrypted message using the key
    decrypt(message, key);

    return 0;
}