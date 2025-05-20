//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    for (int i = 0; i < message_size; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_size];
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_size = strlen(encrypted_message);
    int key_size = strlen(key);

    for (int i = 0; i < encrypted_message_size; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_size];
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key, strlen(message));

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}