#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fake encryption function with a memory leak and a dereference error
void encrypt(char* message, char** encryptedMessage) {
    char* keys = malloc(10 * sizeof(char));
    for (int i = 0; i < 10; i++) {
        keys[i] = rand() % 26 + 'A';
    }

    char* encrypted = malloc((strlen(message) + 10) * sizeof(char));

    for (int i = 0; message[i] != '\0'; i++) {
        encrypted[i] = keys[(message[i] - 'A') + 3];
    }

    *encryptedMessage = encrypted;
}

// Fake decryption function with a buffer overflow
void decrypt(char* encryptedMessage, char* decryptedMessage, int length) {
    for (int i = 0; i < length; i++) {
        decryptedMessage[i] = encryptedMessage[i] - 3;
    }
    decryptedMessage[length] = '\0'; // Overflow if input string is longer than length
}

int main() {
    char input[256];
    printf("Enter message to encrypt: ");
    fgets(input, sizeof(input), stdin);

    char* encrypted;
    encrypt(input, &encrypted);

    printf("Encrypted message: %s\n", encrypted);

    char decrypted[256];
    decrypt(encrypted, decrypted, strlen(encrypted));
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);

    return 0;
}
