//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16  // Size of encryption key in bytes

// Custom encryption algorithm using a key
void encrypt(char *plaintext, char *key) {
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    // Initialize a keystream using the provided key
    char keystream[plaintext_len];
    for (int i = 0; i < plaintext_len; i++) {
        keystream[i] = key[i % key_len];
    }

    // XOR plaintext with keystream for encryption
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] ^= keystream[i];
    }
}

int main() {
    // Prompt for the message to encrypt
    char plaintext[100];
    printf("Enter the message to encrypt: ");
    gets(plaintext);

    // Prompt for the encryption key
    char key[KEY_SIZE];
    printf("Enter the encryption key (16 characters): ");
    gets(key);

    // Encrypt the plaintext using the provided key
    encrypt(plaintext, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", plaintext);

    // Allow user to decrypt the message
    char choice;
    printf("Would you like to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Decrypt the message using the same key
        encrypt(plaintext, key);

        // Print the decrypted message
        printf("Decrypted message: %s\n", plaintext);
    }

    return 0;
}