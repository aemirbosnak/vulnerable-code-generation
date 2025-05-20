//Falcon-180B DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretkey"
#define KEY_SIZE 8

// Function to encrypt the message
void encrypt(char *message, int length) {
    int i, j;
    char key[KEY_SIZE];
    strcpy(key, KEY);

    // Encrypt the message
    for (i = 0; i < length; i++) {
        message[i] += key[i % KEY_SIZE];
    }
}

// Function to decrypt the message
void decrypt(char *message, int length) {
    int i, j;
    char key[KEY_SIZE];
    strcpy(key, KEY);

    // Decrypt the message
    for (i = 0; i < length; i++) {
        message[i] -= key[i % KEY_SIZE];
    }
}

int main() {
    char message[100];
    int length;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);
    length = strlen(message);

    // Encrypt the message
    encrypt(message, length);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, length);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}