//Falcon-180B DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret"

void encrypt(char *message) {
    int length = strlen(message);
    int key_index = 0;

    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + KEY[key_index]) % 26 + 'a';
        } else {
            c = c;
        }
        message[i] = c;
        key_index = (key_index + 1) % strlen(KEY);
    }
}

void decrypt(char *message) {
    int length = strlen(message);
    int key_index = 0;

    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' - KEY[key_index] + 26) % 26 + 'a';
        } else {
            c = c;
        }
        message[i] = c;
        key_index = (key_index + 1) % strlen(KEY);
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Encrypted message: ");
    encrypt(message);
    printf("%s\n", message);

    printf("Decrypted message: ");
    decrypt(message);
    printf("%s\n", message);

    return 0;
}