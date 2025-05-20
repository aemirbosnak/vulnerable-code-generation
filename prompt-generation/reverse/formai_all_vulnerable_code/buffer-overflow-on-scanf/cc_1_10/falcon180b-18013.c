//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    char buffer[KEY_SIZE];

    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] ^= key[i % KEY_SIZE];
    }

    strcpy(ciphertext, plaintext);
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i;
    char buffer[KEY_SIZE];

    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] ^= key[i % KEY_SIZE];
    }

    strcpy(plaintext, ciphertext);
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];
    char key[KEY_SIZE];

    // Generate a random key
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    // Get plaintext from user
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Encrypt plaintext
    encrypt(plaintext, key, ciphertext);

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext
    decrypt(ciphertext, key, plaintext);

    // Print plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}