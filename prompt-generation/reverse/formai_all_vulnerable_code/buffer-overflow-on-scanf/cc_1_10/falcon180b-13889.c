//Falcon-180B DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *key, char *message) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (message[i] + key[i % key_length] - 65) % 26 + 65;
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *key, char *message) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            decrypted_message[j] = (message[i] - key[i % key_length] - 65 + 26) % 26 + 65;
            j++;
        } else {
            decrypted_message[j] = message[i];
            j++;
        }
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf("%s", message);

    encrypt(key, message);
    decrypt(key, message);

    return 0;
}