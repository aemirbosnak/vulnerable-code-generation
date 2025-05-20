//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char key[], int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char message[], char key[], char encrypted_message[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = 'a' + (message[i] - 'a' + key_length) % 26;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
}

void decrypt_message(char encrypted_message[], char key[], char decrypted_message[]) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = 'a' + (encrypted_message[i] - 'a' - key_length + 26) % 26;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Generate encryption key
    generate_key(key, MAX_KEY_LENGTH);

    // Encrypt message
    encrypt_message(message, key, encrypted_message);

    // Display encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    decrypt_message(encrypted_message, key, decrypted_message);

    // Display decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}