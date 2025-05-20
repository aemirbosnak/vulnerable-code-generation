//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mySecretKey"
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

void encrypt(char *message, char *key) {
    int i, j;
    char *result = (char *)malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = toupper(message[i] + ((int)key[i % strlen(key)] - 97) % 26);
        } else {
            result[j++] = message[i];
        }
    }

    result[j] = '\0';

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, char *key) {
    int i, j;
    char *result = (char *)malloc(strlen(message) + 1);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[j++] = ((int)message[i] - 65 - ((int)key[i % strlen(key)] - 97) % 26) % 26 + 97;
        } else {
            result[j++] = message[i];
        }
    }

    result[j] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter a secret key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}