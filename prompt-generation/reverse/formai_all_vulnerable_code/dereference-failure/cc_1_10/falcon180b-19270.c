//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

// Function to generate a random key of length 'len'
void generate_key(char *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int len = strlen(message);
    char encrypted_message[len + 1];
    encrypted_message[len] = '\0';

    // Encrypt each character in the message
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + (int)key[i % MAX_KEY_LEN]) % 26 + 'a';
        }
        encrypted_message[i] = c;
    }

    // Copy the encrypted message to the original message
    strcpy(message, encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char *message, char *key) {
    int len = strlen(message);
    char decrypted_message[len + 1];
    decrypted_message[len] = '\0';

    // Decrypt each character in the message
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - (int)key[i % MAX_KEY_LEN] + 26) % 26 + 'a';
        }
        decrypted_message[i] = c;
    }

    // Copy the decrypted message to the original message
    strcpy(message, decrypted_message);
}

int main() {
    char message[1000];
    char key[MAX_KEY_LEN];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    // Generate a random key
    generate_key(key, MAX_KEY_LEN);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}