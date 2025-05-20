//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY "secret key"

void encrypt(char* message, int key) {
    int i, j, len = strlen(message);
    char encrypted[len];

    for (i = 0, j = 0; i < len; i++, j++) {
        if (j % key == 0) {
            encrypted[i] = message[i];
        } else {
            encrypted[i] = message[len - 1 - (i - j % key)];
        }
    }

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* message, int key) {
    int i, j, len = strlen(message);
    char decrypted[len];

    for (i = 0, j = 0; i < len; i++, j++) {
        if (j % key == 0) {
            decrypted[i] = message[i];
        } else {
            decrypted[i] = message[len - 1 - (i - j % key)];
        }
    }

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}