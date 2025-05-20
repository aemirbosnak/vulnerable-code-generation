//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

void encrypt(char *message, char *key, int key_length, int message_length) {
    if (message_length == 0) {
        printf("Message encrypted: %s\n", message);
        return;
    }
    int i;
    for (i = 0; i < key_length; i++) {
        char c = key[i];
        if (c >= 'a' && c <= 'z') {
            c = c + 'A' - 'a';
        }
        message[i] = c;
    }
    encrypt(message + 1, key, key_length, message_length - 1);
}

void decrypt(char *message, char *key, int key_length, int message_length) {
    if (message_length == 0) {
        printf("Message decrypted: %s\n", message);
        return;
    }
    int i;
    for (i = 0; i < key_length; i++) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') {
            c = c + 'a' - 'A';
        }
        message[i] = c;
    }
    decrypt(message + 1, key, key_length, message_length - 1);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter message to be encrypted: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(message, key, strlen(key), strlen(message));
    printf("Encrypted message: %s\n", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    decrypt(message, key, strlen(key), strlen(message));
    printf("Decrypted message: %s\n", message);
    return 0;
}