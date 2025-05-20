//Falcon-180B DATASET v1.0 Category: Encryption ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[length] = '\0';
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + key_length) % 26 + 'a';
        }
        encrypted_message[i] = c;
    }
    encrypted_message[message_length] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    for (int i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            c = (c - 'a' - key_length + 26) % 26 + 'a';
        }
        message[i] = c;
    }
    message[encrypted_message_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key, strlen(message));

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}