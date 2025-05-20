//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char message[MAX_MESSAGE_LENGTH];
    int message_length;
} Cryptography;

void encrypt(Cryptography *crypt) {
    int i, j;
    for (i = 0, j = 0; i < crypt->message_length; i++) {
        if (isalpha(crypt->message[i])) {
            crypt->message[i] = toupper(crypt->message[i]);
        }
    }

    for (i = 0; i < crypt->message_length; i++) {
        int key_index = (int)crypt->message[i] - 65;
        if (key_index >= 0 && key_index < crypt->key_length) {
            crypt->message[i] = crypt->key[key_index];
        }
    }
}

void decrypt(Cryptography *crypt) {
    int i, j;
    for (i = 0, j = 0; i < crypt->message_length; i++) {
        if (isalpha(crypt->message[i])) {
            crypt->message[i] = toupper(crypt->message[i]);
        }
    }

    for (i = 0; i < crypt->message_length; i++) {
        int key_index = (int)crypt->message[i] - 65;
        if (key_index >= 0 && key_index < crypt->key_length) {
            int message_index = (int)crypt->key[key_index] - 65;
            if (message_index >= 0 && message_index < 26) {
                crypt->message[i] = (char)message_index + 65;
            }
        }
    }
}

int main() {
    Cryptography crypt;
    printf("Enter key: ");
    scanf("%s", crypt.key);
    crypt.key_length = strlen(crypt.key);

    printf("Enter message: ");
    scanf("%s", crypt.message);
    crypt.message_length = strlen(crypt.message);

    encrypt(&crypt);
    printf("Encrypted message: %s\n", crypt.message);

    decrypt(&crypt);
    printf("Decrypted message: %s\n", crypt.message);

    return 0;
}