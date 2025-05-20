//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 8

// Function to encrypt the message using XOR encryption
void encrypt(char* message, int length) {
    char key[BLOCK_SIZE];
    strncpy(key, KEY, BLOCK_SIZE);

    for (int i = 0; i < length; i++) {
        message[i] ^= key[i % BLOCK_SIZE];
    }
}

// Function to decrypt the message using XOR encryption
void decrypt(char* message, int length) {
    char key[BLOCK_SIZE];
    strncpy(key, KEY, BLOCK_SIZE);

    for (int i = 0; i < length; i++) {
        message[i] ^= key[i % BLOCK_SIZE];
    }
}

// Function to encrypt and decrypt the message
void process_message(char* message, int length, int mode) {
    if (mode == 1) {
        encrypt(message, length);
        printf("Encrypted message: %s\n", message);
    } else if (mode == 2) {
        decrypt(message, length);
        printf("Decrypted message: %s\n", message);
    }
}

int main() {
    char message[100];
    int length, mode;

    // Get message and length from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter length of message: ");
    scanf("%d", &length);

    // Get mode from user
    printf("Enter mode (1 for encrypt, 2 for decrypt): ");
    scanf("%d", &mode);

    // Process message
    process_message(message, length, mode);

    return 0;
}