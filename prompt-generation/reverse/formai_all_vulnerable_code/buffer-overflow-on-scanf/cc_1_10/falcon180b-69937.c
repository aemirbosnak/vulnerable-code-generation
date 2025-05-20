//Falcon-180B DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i, j;
    char encrypted_message[message_len + 1];

    for (i = 0, j = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[j];
        j++;
        if (j == key_len) {
            j = 0;
        }
    }
    encrypted_message[message_len] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int message_len = strlen(encrypted_message);
    int key_len = strlen(key);
    int i, j;
    char decrypted_message[message_len + 1];

    for (i = 0, j = 0; i < message_len; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[j];
        j++;
        if (j == key_len) {
            j = 0;
        }
    }
    decrypted_message[message_len] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_LENGTH + 1];
    char key[MAX_KEY_LENGTH + 1];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}