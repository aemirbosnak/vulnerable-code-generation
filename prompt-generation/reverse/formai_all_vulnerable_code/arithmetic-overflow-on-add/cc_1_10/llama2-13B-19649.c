//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10
#define MESSAGE_SIZE 20

// Definition of the cipher
typedef struct {
    char key[KEY_SIZE];
    int index;
} cipher_t;

// Function to encrypt a message
void encrypt(cipher_t *cipher, char *message) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        // Shift the message by the key index
        j = (message[i] + cipher->index) % 26;
        message[i] = j + 'A';
        cipher->index = (cipher->index + 1) % KEY_SIZE;
    }
}

// Function to decrypt an encrypted message
void decrypt(cipher_t *cipher, char *message) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        // Shift the message by the key index in reverse
        j = (message[i] - 'A') % 26;
        message[i] = j - cipher->index;
        cipher->index = (cipher->index + 1) % KEY_SIZE;
    }
}

int main() {
    char message[] = "This is a secret message";
    cipher_t cipher;

    // Generate a random key
    for (int i = 0; i < KEY_SIZE; i++) {
        cipher.key[i] = 'A' + (rand() % 26);
    }

    // Encrypt the message
    encrypt(&cipher, message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(&cipher, message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}