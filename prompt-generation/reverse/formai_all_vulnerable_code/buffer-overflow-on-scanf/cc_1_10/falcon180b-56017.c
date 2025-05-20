//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[j % KEY_SIZE];
            j++;
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[j % KEY_SIZE];
            j++;
        }
    }
}

int main() {
    char message[100], key[KEY_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Enter decryption key: ");
    scanf("%s", key);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}