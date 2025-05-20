//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

void generate_key(char* key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size] = '\0';
}

void encrypt(char* message, char* key, char* encrypted) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    if (key_size > message_size) {
        key_size = message_size;
    }

    for (int i = 0; i < message_size; i++) {
        encrypted[i] = message[i] ^ key[i % key_size];
    }
    encrypted[message_size] = '\0';
}

void decrypt(char* encrypted, char* key, char* message) {
    int encrypted_size = strlen(encrypted);
    int key_size = strlen(key);

    if (key_size > encrypted_size) {
        key_size = encrypted_size;
    }

    for (int i = 0; i < encrypted_size; i++) {
        message[i] = encrypted[i] ^ key[i % key_size];
    }
    message[encrypted_size] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted[MAX_MESSAGE_SIZE];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    srand(time(NULL));
    generate_key(key, rand() % MAX_KEY_SIZE + 1);

    printf("Encrypted message: ");
    encrypt(message, key, encrypted);
    printf("%s\n", encrypted);

    printf("Decrypted message: ");
    decrypt(encrypted, key, message);
    printf("%s\n", message);

    return 0;
}