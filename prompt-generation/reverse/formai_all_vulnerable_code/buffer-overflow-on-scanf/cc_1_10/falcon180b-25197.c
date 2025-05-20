//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 1024

// Function to generate a random key
void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the given message using the key
void encrypt(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_index = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = 'a' + ((message[i] - 'a' + key[key_index]) % 26);
            key_index++;
            if (key_index >= strlen(key)) {
                key_index = 0;
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Function to decrypt the given message using the key
void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_index = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = 'a' + ((encrypted_message[i] - 'a' - key[key_index]) % 26 + 26) % 26;
            key_index++;
            if (key_index >= strlen(key)) {
                key_index = 0;
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    srand(time(NULL));

    char message[MAX_KEY_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    char key[MAX_KEY_SIZE];
    generate_key(key, strlen(message));

    char encrypted_message[MAX_KEY_SIZE];
    encrypt(message, key, encrypted_message);

    char decrypted_message[MAX_KEY_SIZE];
    decrypt(encrypted_message, key, decrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}