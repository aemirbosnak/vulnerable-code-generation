//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_BLOCK_SIZE 8

// Function to encrypt a block of text
void encrypt_block(char* plain_text, char* key, char* cipher_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plain_text); i++, j++) {
        if (j == MAX_BLOCK_SIZE) {
            cipher_text[j] = '\0';
            encrypt_block(plain_text + i, key, cipher_text + j + 1);
            break;
        }
        int k = (int)key[j % strlen(key)] - 65;
        cipher_text[j] = (char)((int)plain_text[i] + k % 26 + 65);
    }
}

// Function to decrypt a block of text
void decrypt_block(char* cipher_text, char* key, char* plain_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++, j++) {
        if (j == MAX_BLOCK_SIZE) {
            plain_text[j] = '\0';
            decrypt_block(cipher_text + i, key, plain_text + j + 1);
            break;
        }
        int k = (int)key[j % strlen(key)] - 65;
        plain_text[j] = (char)((int)cipher_text[i] - k % 26 - 65);
    }
}

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = (char)(rand() % 26 + 65);
    }
}

int main() {
    char plain_text[1000];
    char cipher_text[1000];
    char key[MAX_KEY_LENGTH];
    char decrypted_text[1000];

    // Get input from user
    printf("Enter the plain text to be encrypted:\n");
    scanf("%s", plain_text);

    // Generate a random key
    generate_key(key);

    // Encrypt the plain text
    encrypt_block(plain_text, key, cipher_text);

    // Print the encrypted text and key
    printf("Encrypted text: %s\n", cipher_text);
    printf("Key: %s\n", key);

    // Decrypt the encrypted text
    decrypt_block(cipher_text, key, decrypted_text);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}