//Falcon-180B DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_STRING_LENGTH 512

void encrypt(char *key, char *message) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    int i, j;
    char encrypted_message[MAX_STRING_LENGTH];

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int k = (int) c - 97;
            k = (k + key_length) % 26;
            encrypted_message[j++] = (char) (k + 97);
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *key, char *message) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    int i, j;
    char decrypted_message[MAX_STRING_LENGTH];

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int k = (int) c - 97;
            k = (26 - k + key_length) % 26;
            decrypted_message[j++] = (char) (k + 97);
        } else {
            decrypted_message[j++] = message[i];
        }
    }
    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_STRING_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    encrypt(key, message);
    decrypt(key, message);

    return 0;
}