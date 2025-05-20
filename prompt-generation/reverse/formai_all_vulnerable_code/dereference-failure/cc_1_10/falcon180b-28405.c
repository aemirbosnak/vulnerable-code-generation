//Falcon-180B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 16
#define MAX_PLAINTEXT_LENGTH 1024
#define MAX_CIPHERTEXT_LENGTH (MAX_PLAINTEXT_LENGTH + 1)

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(char *plaintext, char *key, char *ciphertext, int key_length) {
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = toupper(plaintext[i]) - 'A' + 1;
            ciphertext[i] = plaintext[i] + 'A';
        }
    }

    for (int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = ciphertext[i] + key[i % key_length];
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext, int key_length) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = ciphertext[i] - key[i % key_length] + 'A' - 1;
    }

    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = ciphertext[i] - 'A' + 1;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char ciphertext[MAX_CIPHERTEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a string to encrypt: ");
    fgets(plaintext, MAX_PLAINTEXT_LENGTH, stdin);

    generate_key(key, MAX_KEY_LENGTH);

    encrypt(plaintext, key, ciphertext, MAX_KEY_LENGTH);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext, MAX_KEY_LENGTH);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}