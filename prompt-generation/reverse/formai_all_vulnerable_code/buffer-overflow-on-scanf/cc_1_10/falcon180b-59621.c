//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 4096

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
} EncryptionKey;

EncryptionKey generate_key(int key_size) {
    EncryptionKey result;
    result.key_size = key_size;
    for (int i = 0; i < key_size; i++) {
        result.key[i] = rand() % 26 + 'a';
    }
    result.key[key_size] = '\0';
    return result;
}

void encrypt_message(EncryptionKey key, char* message, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 'a' + key.key_size) % 26 + 'a';
        }
        encrypted_message[i] = c;
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt_message(EncryptionKey key, char* encrypted_message, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            c = (c - 'a' - key.key_size + 26) % 26 + 'a';
        }
        decrypted_message[i] = c;
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    EncryptionKey key = generate_key(10);
    char message[MAX_MESSAGE_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    char encrypted_message[MAX_MESSAGE_SIZE];
    encrypt_message(key, message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    char decrypted_message[MAX_MESSAGE_SIZE];
    decrypt_message(key, encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}