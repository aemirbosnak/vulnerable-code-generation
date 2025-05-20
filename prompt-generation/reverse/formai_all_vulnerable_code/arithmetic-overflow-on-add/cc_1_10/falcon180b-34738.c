//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 32
#define IV_SIZE 16

int main() {
    unsigned char key[KEY_SIZE] = {0};
    unsigned char iv[IV_SIZE] = {0};
    unsigned char plaintext[256] = "This is a secret message.";
    unsigned char ciphertext[256 + EVP_MAX_IV_LENGTH] = {0};
    int ciphertext_len, plaintext_len = strlen((char *)plaintext);
    EVP_CIPHER_CTX *ctx = NULL;
    int key_len, iv_len;

    // Generate a random key and IV
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    // Initialize the encryption context
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("Error: Failed to create encryption context\n");
        exit(1);
    }

    // Set the encryption algorithm and mode
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Error: Failed to initialize encryption\n");
        exit(1);
    }

    // Encrypt the plaintext
    if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len)) {
        printf("Error: Failed to encrypt data\n");
        exit(1);
    }

    // Finalize the encryption and get the total ciphertext length
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &key_len)) {
        printf("Error: Failed to finalize encryption\n");
        exit(1);
    }
    ciphertext_len += key_len;

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);

    // Print the ciphertext and its length
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");
    printf("Ciphertext length: %d bytes\n", ciphertext_len);

    return 0;
}