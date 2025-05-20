//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to encrypt a block of data using the key
void encrypt(char *block, char *key) {
    int i, j;
    char *key_index = malloc(KEY_SIZE * sizeof(char));
    for (i = 0; i < KEY_SIZE; i++) {
        key_index[i] = tolower(key[i]);
    }

    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key_index[(i % KEY_SIZE)];
    }
}

// Function to decrypt a block of data using the key
void decrypt(char *block, char *key) {
    int i;
    char *key_index = malloc(KEY_SIZE * sizeof(char));
    for (i = 0; i < KEY_SIZE; i++) {
        key_index[i] = tolower(key[i]);
    }

    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key_index[(i % KEY_SIZE)];
    }
}

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

int main() {
    char plaintext[100];
    char key[KEY_SIZE];

    // Generate a random key
    generate_key(key);

    // Get the plaintext from the user
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, key);

    // Print the encrypted plaintext
    printf("Encrypted plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    // Decrypt the encrypted plaintext
    decrypt(plaintext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}