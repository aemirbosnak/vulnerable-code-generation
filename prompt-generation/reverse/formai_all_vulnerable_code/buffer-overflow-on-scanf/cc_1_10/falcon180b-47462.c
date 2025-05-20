//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(unsigned char *key) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message using the key
void encrypt(unsigned char *message, unsigned char *key, unsigned char *ciphertext) {
    int message_length = strlen((char *)message);
    int ciphertext_length = message_length + KEY_SIZE;

    for (int i = 0; i < message_length; i++) {
        ciphertext[i] = message[i] ^ key[i % KEY_SIZE];
    }

    for (int i = message_length; i < ciphertext_length; i++) {
        ciphertext[i] = rand() % 256;
    }
}

// Function to decrypt the message using the key
void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *message) {
    int ciphertext_length = strlen((char *)ciphertext);
    int message_length = ciphertext_length - KEY_SIZE;

    for (int i = 0; i < message_length; i++) {
        message[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char message[100];
    unsigned char ciphertext[100];

    // Generate a random key
    generate_key(key);

    // Prompt the user to enter a message
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key, ciphertext);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < strlen((char *)ciphertext); i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the message using the key
    decrypt(ciphertext, key, message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}