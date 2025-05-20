//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 36 + 'A';
    }
}

void encrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'A' + key[i % KEY_LENGTH]) % 26 + 'A';
        }
        message[i] = c;
    }
}

void decrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'A' - key[i % KEY_LENGTH] + 26) % 26 + 'A';
        }
        message[i] = c;
    }
}

int main() {
    char message[1000];
    char key[KEY_LENGTH];

    printf("Enter a message: ");
    scanf("%s", message);

    generate_key(key);
    printf("Encrypting message...\n");
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Decrypting message...\n");
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}