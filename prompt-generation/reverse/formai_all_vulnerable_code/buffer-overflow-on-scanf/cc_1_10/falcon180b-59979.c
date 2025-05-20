//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

// Function to generate a random key
void generate_key(char key[KEY_LENGTH]) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH - 1] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char message[100], char key[KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + key[i % KEY_LENGTH]) % 26 + 'a';
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char message[100], char key[KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' - key[i % KEY_LENGTH] + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[100];
    char key[KEY_LENGTH];

    // Get message from user
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);

    // Generate random key
    generate_key(key);

    // Encrypt and display the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}