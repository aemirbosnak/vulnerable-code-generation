//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i, j;
    char encrypted_message[MAX_SIZE];

    for (i = 0, j = 0; i < message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ key[j];
    }
    encrypted_message[message_len] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_len = strlen(encrypted_message);
    int key_len = strlen(key);
    int i, j;
    char decrypted_message[MAX_SIZE];

    for (i = 0, j = 0; i < encrypted_message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }
    decrypted_message[encrypted_message_len] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    int choice;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter a key for encryption/decryption: ");
    scanf("%s", key);

    printf("Enter 1 to encrypt the message or 2 to decrypt the message: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}