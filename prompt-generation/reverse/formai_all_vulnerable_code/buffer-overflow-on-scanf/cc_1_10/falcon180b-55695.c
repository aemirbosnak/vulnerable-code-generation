//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 1024

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *message, char *key, int key_length, char *ciphertext) {
    int message_length = strlen(message);
    int i = 0, j = 0;
    char temp_message[MAX_KEY_LENGTH];
    strcpy(temp_message, message);

    for (int k = 0; k < key_length; k++) {
        key[k] = (key[k] + k) % 256;
    }

    for (int k = 0; k < message_length; k++) {
        ciphertext[k] = temp_message[k] ^ key[k % key_length];
    }
}

void decrypt(char *ciphertext, char *key, int key_length, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int i = 0, j = 0;
    char temp_ciphertext[MAX_KEY_LENGTH];
    strcpy(temp_ciphertext, ciphertext);

    for (int k = 0; k < key_length; k++) {
        key[k] = (key[k] + k) % 256;
    }

    for (int k = 0; k < ciphertext_length; k++) {
        message[k] = temp_ciphertext[k] ^ key[k % key_length];
    }
}

int main() {
    char message[MAX_KEY_LENGTH], ciphertext[MAX_KEY_LENGTH], key[MAX_KEY_LENGTH];
    int key_length;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key length (1-1024): ");
    scanf("%d", &key_length);

    generate_key(key, key_length);

    encrypt(message, key, key_length, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, key_length, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}