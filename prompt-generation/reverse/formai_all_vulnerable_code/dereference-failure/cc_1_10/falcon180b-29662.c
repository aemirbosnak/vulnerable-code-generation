//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_message_length = message_length + KEY_SIZE;

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % KEY_SIZE];
    }

    for (int i = message_length; i < encrypted_message_length; i++) {
        encrypted_message[i] = key[(i - message_length) % KEY_SIZE];
    }
}

// Function to decrypt an encrypted message using a key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int decrypted_message_length = encrypted_message_length - KEY_SIZE;

    for (int i = 0; i < decrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    char key[KEY_SIZE];
    generate_key(key);

    char message[100] = "Hello, world!";
    char encrypted_message[100];
    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[100];
    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}