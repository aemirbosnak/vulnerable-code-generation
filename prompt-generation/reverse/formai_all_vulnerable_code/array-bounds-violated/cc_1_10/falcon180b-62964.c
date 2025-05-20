//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - 'a';
            int key_index = (i % key_length) % MAX_KEY_LENGTH;
            encrypted_message[i] = (char) (((letter_index + key[key_index]) % 26) + 'A');
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[encrypted_message_length];

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            int letter_index = tolower(encrypted_message[i]) - 'a';
            int key_index = (i % key_length) % MAX_KEY_LENGTH;
            decrypted_message[i] = (char) (((letter_index - key[key_index] + 26) % 26) + 'A');
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    generate_key(key);

    printf("Encrypting message...\n");
    encrypt(message, key);

    printf("Decrypting message...\n");
    decrypt(message, key);

    return 0;
}