//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_BLOCK_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char iv[MAX_KEY_SIZE];
    int iv_size;
    char mode;
} encryption_params;

void encrypt(char* plaintext, encryption_params* params) {
    char ciphertext[MAX_BLOCK_SIZE + 1];
    int key_index = 0;
    int iv_index = 0;
    int mode_index = 0;

    for (int i = 0; i < strlen(plaintext); i++) {
        char c = toupper(plaintext[i]);

        if (isalpha(c)) {
            int key_char_index = key_index % params->key_size;
            int iv_char_index = iv_index % params->iv_size;

            ciphertext[i] = (c + params->key[key_char_index] + params->iv[iv_char_index]) % 26 + 'A';

            key_index++;
            iv_index++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char* ciphertext, encryption_params* params) {
    char plaintext[MAX_BLOCK_SIZE + 1];
    int key_index = 0;
    int iv_index = 0;
    int mode_index = 0;

    for (int i = 0; i < strlen(ciphertext); i++) {
        char c = toupper(ciphertext[i]);

        if (isalpha(c)) {
            int key_char_index = key_index % params->key_size;
            int iv_char_index = iv_index % params->iv_size;

            int decrypted_char = (c - params->key[key_char_index] - params->iv[iv_char_index] + 26) % 26 + 'A';

            plaintext[i] = decrypted_char;

            key_index++;
            iv_index++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    printf("Plaintext: %s\n", plaintext);
}

int main() {
    encryption_params params;
    char plaintext[MAX_BLOCK_SIZE + 1];
    char ciphertext[MAX_BLOCK_SIZE + 1];
    int choice;

    printf("Enter the encryption mode (AES, DES, RSA): ");
    scanf("%s", params.mode);

    printf("Enter the key size (must be between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &params.key_size);

    printf("Enter the initialization vector size (must be between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &params.iv_size);

    printf("Enter the key: ");
    scanf("%s", params.key);

    printf("Enter the initialization vector: ");
    scanf("%s", params.iv);

    while (1) {
        printf("\nEnter 1 to encrypt or 2 to decrypt: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the plaintext: ");
            scanf("%s", plaintext);
            encrypt(plaintext, &params);
        } else if (choice == 2) {
            printf("Enter the ciphertext: ");
            scanf("%s", ciphertext);
            decrypt(ciphertext, &params);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}