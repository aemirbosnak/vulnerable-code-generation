//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32

// Function to generate a random key of length keylen
void generate_key(char* key, int keylen) {
    for (int i = 0; i < keylen; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[keylen] = '\0';
}

// Function to encrypt a message using the Caesar cipher
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_message_length = message_length + 1;

    encrypted_message[encrypted_message_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key_length) % 26 + 'A';
        }
        encrypted_message[i] = c;
    }
}

// Function to decrypt a message using the Caesar cipher
void decrypt(char* encrypted_message, char* key, char* message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int message_length = encrypted_message_length - 1;

    for (int i = 0; i < encrypted_message_length; i++) {
        char c = toupper(encrypted_message[i]);
        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - key_length + 26) % 26 + 'A';
        }
        message[i] = c;
    }
    message[message_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_KEY_LENGTH];
    char encrypted_message[MAX_KEY_LENGTH];
    char decrypted_message[MAX_KEY_LENGTH];

    generate_key(key, MAX_KEY_LENGTH);

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_KEY_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}