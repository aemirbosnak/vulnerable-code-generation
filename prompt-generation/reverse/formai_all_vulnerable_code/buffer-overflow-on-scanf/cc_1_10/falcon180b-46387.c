//Falcon-180B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define KEY_LENGTH 8

void generate_key() {
    char key[KEY_LENGTH];
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    printf("Key: %s\n", key);
}

void encrypt(char message[MAX_LENGTH], char key[KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A' + key[i % KEY_LENGTH] - 'A') % 26);
            } else {
                message[i] = 'a' + ((message[i] - 'a' + key[i % KEY_LENGTH] - 'A') % 26);
            }
        }
    }
}

void decrypt(char encrypted_message[MAX_LENGTH], char key[KEY_LENGTH]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                encrypted_message[i] = 'A' + ((encrypted_message[i] - 'A' - key[i % KEY_LENGTH] + 26) % 26);
            } else {
                encrypted_message[i] = 'a' + ((encrypted_message[i] - 'a' - key[i % KEY_LENGTH] + 26) % 26);
            }
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    char encrypted_message[MAX_LENGTH];
    char key[KEY_LENGTH];

    printf("Enter message: ");
    scanf("%s", message);

    generate_key();

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}