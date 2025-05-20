//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Recursive function to encrypt the message
void encrypt(char *message, char *key, int key_length, int *index, char *encrypted_message) {
    if (*index >= strlen(message)) {
        encrypted_message[*index] = '\0';
        return;
    }

    if (isalpha(message[*index])) {
        int shift = (int)message[*index] - 65;
        int new_index = *index % key_length;
        encrypted_message[*index] = key[new_index + shift];
        (*index)++;
    } else {
        encrypted_message[*index] = message[*index];
        (*index)++;
    }

    encrypt(message, key, key_length, index, encrypted_message);
}

// Recursive function to decrypt the message
void decrypt(char *encrypted_message, char *key, int key_length, int *index, char *decrypted_message) {
    if (*index >= strlen(encrypted_message)) {
        decrypted_message[*index] = '\0';
        return;
    }

    if (isalpha(encrypted_message[*index])) {
        int shift = (int)encrypted_message[*index] - 65;
        int new_index = *index % key_length;
        decrypted_message[*index] = 65 + (key[new_index + shift] - 65);
        (*index)++;
    } else {
        decrypted_message[*index] = encrypted_message[*index];
        (*index)++;
    }

    decrypt(encrypted_message, key, key_length, index, decrypted_message);
}

// Function to generate a random key
void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = 'a' + rand() % 26;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int message_length, key_length, index = 0;

    printf("Enter message: ");
    scanf("%s", message);
    message_length = strlen(message);

    printf("Enter key length (1-100): ");
    scanf("%d", &key_length);

    generate_key(key, key_length);

    encrypt(message, key, key_length, &index, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, key_length, &index, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}