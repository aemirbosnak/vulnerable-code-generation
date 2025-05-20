//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (message_length > MAX_MESSAGE_LENGTH || key_length > MAX_KEY_LENGTH) {
        printf("Error: Message or key is too long.\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (message_length > MAX_MESSAGE_LENGTH || key_length > MAX_KEY_LENGTH) {
        printf("Error: Message or key is too long.\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}