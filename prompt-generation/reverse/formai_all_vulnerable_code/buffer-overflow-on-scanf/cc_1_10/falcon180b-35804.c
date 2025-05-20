//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void encrypt(char *message, char *key) {
    int i, j, k;
    char *result = malloc(strlen(message) + 1);

    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            result[i] = 'A';
            k = 0;

            if (isupper(message[i])) {
                k = 65;
            }

            j = (message[i] - k + key[i % strlen(key)]) % SIZE;

            if (isupper(message[i])) {
                result[i] = j + k;
            } else {
                result[i] = j + 97;
            }
        } else {
            result[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", result);
    free(result);
}

void decrypt(char *message, char *key) {
    int i, j, k;
    char *result = malloc(strlen(message) + 1);

    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            result[i] = 'A';
            k = 0;

            if (isupper(message[i])) {
                k = 65;
            }

            j = ((message[i] - k - key[i % strlen(key)]) % SIZE + 26) % SIZE;

            if (isupper(message[i])) {
                result[i] = j + k;
            } else {
                result[i] = j + 97;
            }
        } else {
            result[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", result);
    free(result);
}

int main() {
    char message[100], key[100];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}