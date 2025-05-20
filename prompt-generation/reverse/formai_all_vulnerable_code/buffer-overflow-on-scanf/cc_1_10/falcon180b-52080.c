//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1000

// Function to encrypt the given string using the given key
void encrypt(char *message, char *key) {
    int i, j, key_index = 0;
    char encrypted_message[strlen(message)];

    // Initialize the key index
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key_index = key_index % strlen(key);
        } else {
            key_index++;
        }
    }

    // Encrypt the message
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((message[i] + key_index - 'a' + 1) % 26 + 'a');
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the given string using the given key
void decrypt(char *message, char *key) {
    int i, j, key_index = 0;
    char decrypted_message[strlen(message)];

    // Initialize the key index
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key_index = key_index % strlen(key);
        } else {
            key_index++;
        }
    }

    // Decrypt the message
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            decrypted_message[i] = (char) ((message[i] - key_index - 'a' + 26) % 26 + 'a');
            key_index = (key_index + 1) % strlen(key);
        } else {
            decrypted_message[i] = message[i];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_SIZE], key[MAX_KEY_SIZE];

    // Get the message and key from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}