//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key, int direction) {
    // Base case
    if (*message == '\0') {
        return;
    }

    // Encrypt uppercase characters
    if (*message >= 'A' && *message <= 'Z') {
        *message = (*message + key - 65) % 26 + 65;
    }
    // Encrypt lowercase characters
    else if (*message >= 'a' && *message <= 'z') {
        *message = (*message + key - 97) % 26 + 97;
    }

    // Recursive case
    encrypt(message + 1, key, direction);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key, int direction) {
    // Base case
    if (*message == '\0') {
        return;
    }

    // Decrypt uppercase characters
    if (*message >= 'A' && *message <= 'Z') {
        *message = (*message - key - 65) % 26 + 65;
    }
    // Decrypt lowercase characters
    else if (*message >= 'a' && *message <= 'z') {
        *message = (*message - key - 97) % 26 + 97;
    }

    // Recursive case
    decrypt(message + 1, key, direction);
}

int main() {
    char message[1000];
    int key, direction;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get encryption/decryption key from user
    printf("Enter encryption/decryption key (0-25): ");
    scanf("%d", &key);

    // Get encryption/decryption direction from user
    printf("Enter encryption/decryption direction (0 for encryption, 1 for decryption): ");
    scanf("%d", &direction);

    // Encrypt or decrypt message based on user input
    if (direction == 0) {
        encrypt(message, key, direction);
    }
    else {
        decrypt(message, key, direction);
    }

    // Print encrypted/decrypted message
    printf("Encrypted/Decrypted message: %s\n", message);

    return 0;
}