//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define ENCRYPT 1
#define DECRYPT 2
#define INVALID_COMMAND 3

void encrypt(char *message, int key) {
    int i, j;
    char buffer[SIZE];
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            buffer[i] = (message[i] + key - 65) % 26 + 65;
        } else {
            buffer[i] = message[i];
        }
    }
    printf("Encrypted message: %s\n", buffer);
}

void decrypt(char *message, int key) {
    int i, j;
    char buffer[SIZE];
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            buffer[i] = (message[i] - key - 65) % 26 + 65;
        } else {
            buffer[i] = message[i];
        }
    }
    printf("Decrypted message: %s\n", buffer);
}

int main() {
    char message[SIZE];
    int key, choice;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the encryption/decryption key: ");
    scanf("%d", &key);

    printf("Enter 1 for encryption or 2 for decryption: ");
    scanf("%d", &choice);

    switch (choice) {
        case ENCRYPT:
            encrypt(message, key);
            break;
        case DECRYPT:
            decrypt(message, key);
            break;
        default:
            printf("Invalid command\n");
            return INVALID_COMMAND;
    }

    return 0;
}