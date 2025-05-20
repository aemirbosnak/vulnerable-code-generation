//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the given message using the given key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_length = message_length + KEY_SIZE;

    for (int i = 0; i < encrypted_length; i++) {
        encrypted_message[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[j];
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }
}

// Function to decrypt the given message using the given key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int decrypted_length = encrypted_length - KEY_SIZE;

    for (int i = 0; i < decrypted_length; i++) {
        decrypted_message[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < encrypted_length; i++) {
        decrypted_message[i - KEY_SIZE] = encrypted_message[i] ^ key[j];
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }
}

int main() {
    char message[100];
    char key[KEY_SIZE];
    char encrypted_message[100];
    char decrypted_message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}