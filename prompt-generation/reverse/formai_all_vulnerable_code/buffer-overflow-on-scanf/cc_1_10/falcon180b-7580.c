//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 16

void encrypt(char *message, char *key) {
    int i, j, k;
    char cipher_message[MAX_LENGTH];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            cipher_message[j++] = (char) (message[i] + key[i % KEY_LENGTH] - 65);
        } else {
            cipher_message[j++] = message[i];
        }
    }
    cipher_message[j] = '\0';

    printf("Encrypted message: %s\n", cipher_message);
}

void decrypt(char *cipher_message, char *key) {
    int i, j, k;
    char message[MAX_LENGTH];

    for (i = 0, j = 0; cipher_message[i]!= '\0'; i++) {
        if (isalpha(cipher_message[i])) {
            message[j++] = (char) (cipher_message[i] - key[i % KEY_LENGTH] - 65 + 26);
        } else {
            message[j++] = cipher_message[i];
        }
    }
    message[j] = '\0';

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}