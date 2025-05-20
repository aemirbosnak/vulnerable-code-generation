//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 16
#define BLOCK_LEN 64

void encrypt(char *message, char *key) {
    char block[BLOCK_LEN];
    char encrypted_message[strlen(message) + 1];
    int len = strlen(message);
    int i, j;

    for (i = 0; i < len; i += BLOCK_LEN) {
        strncpy(block, message + i, BLOCK_LEN);
        block[BLOCK_LEN - 1] = '\0';

        for (j = 0; j < BLOCK_LEN; j++) {
            char ch = toupper(block[j]);

            if (isalpha(ch)) {
                ch = (char) ((ch - 'A' + key[j % KEY_LEN]) % 26 + 'A');
            }

            encrypted_message[i + j] = ch;
        }
    }

    encrypted_message[len] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    char block[BLOCK_LEN];
    char decrypted_message[strlen(encrypted_message) + 1];
    int len = strlen(encrypted_message);
    int i, j;

    for (i = 0; i < len; i += BLOCK_LEN) {
        strncpy(block, encrypted_message + i, BLOCK_LEN);
        block[BLOCK_LEN - 1] = '\0';

        for (j = 0; j < BLOCK_LEN; j++) {
            char ch = toupper(block[j]);

            if (isalpha(ch)) {
                ch = (char) ((ch - 'A' - key[j % KEY_LEN] + 26) % 26 + 'A');
            }

            decrypted_message[i + j] = ch;
        }
    }

    decrypted_message[len] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    char key[KEY_LEN];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key (length %d): ", KEY_LEN);
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}