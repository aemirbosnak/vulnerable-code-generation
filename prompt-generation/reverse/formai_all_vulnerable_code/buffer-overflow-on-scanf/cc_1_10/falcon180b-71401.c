//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100

int shift(char c) {
    if (isupper(c)) {
        return 'A' + (c - 'A' + 13) % 26;
    } else if (islower(c)) {
        return 'a' + (c - 'a' + 13) % 26;
    } else {
        return c;
    }
}

void encrypt(char* message, char* key) {
    int i, j, key_index = 0;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i]);
        } else {
            message[i] = message[i];
        }
    }
}

void decrypt(char* message, char* key) {
    int i, j, key_index = 0;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i]);
        } else {
            message[i] = message[i];
        }
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[1000];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Enter the encrypted message to decrypt: ");
    scanf("%s", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}