//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_length = message_length + 1;
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'A' + key[i % KEY_SIZE]) % 26 + 'A';
        }
        encrypted_message[i] = c;
    }
    encrypted_message[encrypted_length - 1] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int decrypted_length = encrypted_length - 1;
    for (int i = 0; i < encrypted_length; i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            c = (c - 'A' - key[i % KEY_SIZE + 1]) % 26 + 'A';
        }
        decrypted_message[i] = c;
    }
    decrypted_message[decrypted_length] = '\0';
}

int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    char key[KEY_SIZE + 1];

    printf("Enter a message: ");
    scanf("%s", message);

    generate_key(key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}