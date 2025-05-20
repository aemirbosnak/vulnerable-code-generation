//Falcon-180B DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 8
#define KEY_SIZE 8

void encrypt(char *message, char *key) {
    char *result = malloc(strlen(message) + 1);
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = (key[i % KEY_SIZE] == '1')? message[i] ^ 'z' : message[i] ^ 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    printf("Encrypted message: %s\n", result);
    free(result);
}

void decrypt(char *message, char *key) {
    char *result = malloc(strlen(message) + 1);
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = (key[i % KEY_SIZE] == '1')? message[i] ^ 'z' : message[i] ^ 'a';
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    printf("Decrypted message: %s\n", result);
    free(result);
}

int main() {
    char message[100];
    char key[KEY_SIZE];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        scanf(" %c", &key[i]);
    }

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}