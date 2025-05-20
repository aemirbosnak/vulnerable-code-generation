//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] + key[i % strlen(key)]) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            decrypted_message[i] = (message[i] - key[i % strlen(key)]) % 26 + 'A';
        } else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    generate_key(key, strlen(key));
    printf("Key: %s\n", key);

    printf("Enter a message to encrypt:\n");
    scanf("%s", message);
    encrypt(message, key);

    printf("Enter the encrypted message to decrypt:\n");
    scanf("%s", message);
    decrypt(message, key);

    return 0;
}