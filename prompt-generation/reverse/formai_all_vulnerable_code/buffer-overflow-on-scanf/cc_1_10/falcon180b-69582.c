//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char key[], int key_length) {
    for(int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt_message(char message[], char key[], int key_length) {
    char encrypted_message[MAX_MESSAGE_LENGTH];
    memset(encrypted_message, 0, sizeof(encrypted_message));

    for(int i = 0; i < strlen(message); i++) {
        char c = toupper(message[i]);
        int index = (int)c - 65;
        encrypted_message[i] = (index + key_length) % 26 + 'A';
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char encrypted_message[], char key[], int key_length) {
    char decrypted_message[MAX_MESSAGE_LENGTH];
    memset(decrypted_message, 0, sizeof(decrypted_message));

    for(int i = 0; i < strlen(encrypted_message); i++) {
        char c = toupper(encrypted_message[i]);
        int index = (int)c - 65;
        decrypted_message[i] = (index - key_length + 26) % 26 + 'A';
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key to encrypt the message: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt_message(message, key, strlen(key));

    decrypt_message(message, key, strlen(key));

    return 0;
}