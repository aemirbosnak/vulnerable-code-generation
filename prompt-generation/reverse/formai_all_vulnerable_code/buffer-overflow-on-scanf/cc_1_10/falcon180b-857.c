//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} crypt_data;

void encrypt(crypt_data *data) {
    int i, j, key_length = strlen(data->key);
    char message_copy[MAX_MESSAGE_LENGTH];

    strcpy(message_copy, data->message);

    for (i = 0, j = 0; i < strlen(message_copy); i++) {
        if (isalpha(message_copy[i])) {
            if (isupper(message_copy[i])) {
                message_copy[i] = 'A' + (message_copy[i] - 'A' + key_length) % 26;
            } else {
                message_copy[i] = 'a' + (message_copy[i] - 'a' + key_length) % 26;
            }
        } else {
            message_copy[i] = message_copy[i];
        }
    }

    strcpy(data->message, message_copy);
}

void decrypt(crypt_data *data) {
    int i, j, key_length = strlen(data->key);
    char message_copy[MAX_MESSAGE_LENGTH];

    strcpy(message_copy, data->message);

    for (i = 0, j = 0; i < strlen(message_copy); i++) {
        if (isalpha(message_copy[i])) {
            if (isupper(message_copy[i])) {
                message_copy[i] = 'A' + (message_copy[i] - 'A' - key_length + 26) % 26;
            } else {
                message_copy[i] = 'a' + (message_copy[i] - 'a' - key_length + 26) % 26;
            }
        } else {
            message_copy[i] = message_copy[i];
        }
    }

    strcpy(data->message, message_copy);
}

int main() {
    crypt_data data;
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int choice;

    printf("Enter the message to encrypt:\n");
    scanf("%s", message);

    printf("Enter the encryption key:\n");
    scanf("%s", key);

    strcpy(data.key, key);
    strcpy(data.message, message);

    encrypt(&data);

    printf("Encrypted message: %s\n", data.message);

    printf("Enter your choice:\n");
    printf("1. Decrypt\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            decrypt(&data);
            printf("Decrypted message: %s\n", data.message);
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}