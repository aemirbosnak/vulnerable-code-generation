//Falcon-180B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define ROUNDS 4

void encrypt(char* message, char* key) {
    int i, j, k, length = strlen(message);
    char* buffer = (char*)malloc(length + 1);
    strcpy(buffer, message);

    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < length; j++) {
            if (isalpha(buffer[j])) {
                if (isupper(buffer[j])) {
                    buffer[j] = (buffer[j] + key[i % KEY_LENGTH] - 'A' + 26) % 26 + 'A';
                } else {
                    buffer[j] = (buffer[j] + key[i % KEY_LENGTH] - 'a' + 26) % 26 + 'a';
                }
            } else {
                buffer[j] = buffer[j];
            }
        }
    }

    printf("Encrypted message: %s\n", buffer);
    free(buffer);
}

void decrypt(char* message, char* key) {
    int i, j, k, length = strlen(message);
    char* buffer = (char*)malloc(length + 1);
    strcpy(buffer, message);

    for (i = ROUNDS - 1; i >= 0; i--) {
        for (j = 0; j < length; j++) {
            if (isalpha(buffer[j])) {
                if (isupper(buffer[j])) {
                    buffer[j] = (buffer[j] - key[i % KEY_LENGTH] - 'A' + 26) % 26 + 'A';
                } else {
                    buffer[j] = (buffer[j] - key[i % KEY_LENGTH] - 'a' + 26) % 26 + 'a';
                }
            } else {
                buffer[j] = buffer[j];
            }
        }
    }

    printf("Decrypted message: %s\n", buffer);
    free(buffer);
}

int main() {
    char message[1000], key[KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key (16 characters): ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}