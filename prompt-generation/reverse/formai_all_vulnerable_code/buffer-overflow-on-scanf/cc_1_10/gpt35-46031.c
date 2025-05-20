//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encryption Function */
void encrypt(char message[], char key[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int key_offset = 0;

    for (int i = 0; i < message_length; i++) {
        message[i] = (message[i] + key[key_offset]) % 256;
        key_offset = (key_offset + 1) % key_length;
    }
}

/* Decryption Function */
void decrypt(char message[], char key[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int key_offset = 0;

    for (int i = 0; i < message_length; i++) {
        message[i] = (message[i] - key[key_offset] + 256) % 256;
        key_offset = (key_offset + 1) % key_length;
    }
}

/* Main Function */
int main() {
    char message[100];
    char key[100];
    char encrypted_message[100];
    char decrypted_message[100];

    /* Get message input */
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    /* Get key input */
    printf("Enter key: ");
    scanf("%s", key);

    /* Encrypt message */
    strcpy(encrypted_message, message);
    encrypt(encrypted_message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    /* Decrypt message */
    strcpy(decrypted_message, encrypted_message);
    decrypt(decrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}