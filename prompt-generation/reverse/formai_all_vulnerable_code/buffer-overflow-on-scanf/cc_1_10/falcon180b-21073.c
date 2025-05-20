//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j, k;

    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j >= key_length) {
            j = 0;
        }

        encrypted_message[i] = message[i] ^ key[j];
    }

    encrypted_message[message_length] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j, k;

    for (i = 0, j = 0; i < encrypted_message_length; i++, j++) {
        if (j >= key_length) {
            j = 0;
        }

        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }

    decrypted_message[encrypted_message_length] = '\0';
}

int main() {
    char message[100], key[KEY_SIZE], encrypted_message[100], decrypted_message[100];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key, encrypted_message);
    printf("\nEncrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}