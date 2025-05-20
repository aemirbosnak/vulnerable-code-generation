//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[key_size] = '\0';
}

void encrypt_message(char *message, char *key) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    char encrypted_message[MAX_MESSAGE_SIZE];
    int encrypted_message_size = 0;

    for (int i = 0; i < message_size; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + key[i % key_size] - 'a') % 26 + 'a';
        }
        encrypted_message[encrypted_message_size++] = c;
    }

    encrypted_message[encrypted_message_size] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char *message, char *key) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    char decrypted_message[MAX_MESSAGE_SIZE];
    int decrypted_message_size = 0;

    for (int i = 0; i < message_size; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' - key[i % key_size] + 26) % 26 + 'a';
        }
        decrypted_message[decrypted_message_size++] = c;
    }

    decrypted_message[decrypted_message_size] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    char key[MAX_KEY_SIZE];
    generate_key(key, MAX_KEY_SIZE);

    printf("Encrypting message with key: %s\n", key);
    encrypt_message(message, key);

    printf("Decrypting message with key: %s\n", key);
    decrypt_message(message, key);

    return 0;
}