//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 100

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: Message is too long.\n");
        exit(1);
    }

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + key[j % key_length]) % 26 + 'a';
            message[i] = c;
            j++;
        }
    }
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: Message is too long.\n");
        exit(1);
    }

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    int i, j;
    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' - key[j % key_length] + 26) % 26 + 'a';
            message[i] = c;
            j++;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key to encrypt the message: ");
    scanf("%s", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}