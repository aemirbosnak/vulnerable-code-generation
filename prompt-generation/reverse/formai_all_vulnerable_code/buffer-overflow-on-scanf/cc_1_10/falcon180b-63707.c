//Falcon-180B DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j, k;
    char block[BLOCK_SIZE];
    char encrypted_message[strlen(message)];

    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = '\0';
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = message[i] + (rand() % 26);
            }
        }
    }

    for (i = 0; i < strlen(message); i += BLOCK_SIZE) {
        for (j = i, k = 0; j < i + BLOCK_SIZE && k < KEY_SIZE; j++, k++) {
            block[k] = message[j];
        }
        for (j = 0; j < strlen(key) && k < KEY_SIZE; j++, k++) {
            message[i + j] = block[k] ^ key[j];
        }
    }
}

int main() {
    char message[1000], key[KEY_SIZE];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    generate_key(key);
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}