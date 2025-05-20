//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define TAG_SIZE 16

EVP_CIPHER_CTX *ctx;
EVP_CIPHER *cipher;

int main() {
    unsigned char key[KEY_SIZE] = {0};
    unsigned char iv[IV_SIZE] = {0};
    unsigned char tag[TAG_SIZE] = {0};
    unsigned char plaintext[100] = {0};
    unsigned char ciphertext[100] = {0};
    int plaintext_len, ciphertext_len;
    int tag_len;

    // Generate random key and IV
    if (!RAND_bytes(key, KEY_SIZE)) {
        printf("Error generating key\n");
        exit(1);
    }
    if (!RAND_bytes(iv, IV_SIZE)) {
        printf("Error generating IV\n");
        exit(1);
    }

    // Initialize AES-GCM cipher
    cipher = EVP_aes_128_gcm();
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("Error allocating cipher context\n");
        exit(1);
    }
    if (!EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv)) {
        printf("Error initializing decryption context\n");
        exit(1);
    }

    // Read plaintext from stdin
    printf("Enter plaintext:\n");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext_len = strlen(plaintext);

    // Pad plaintext to a multiple of 16 bytes
    plaintext_len += 16 - (plaintext_len % 16);
    plaintext[plaintext_len] = 0;

    // Encrypt plaintext
    if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len)) {
        printf("Error encrypting plaintext\n");
        exit(1);
    }
    ciphertext_len += tag_len;

    // Finalize encryption and get tag
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len - tag_len, &tag_len)) {
        printf("Error finalizing encryption\n");
        exit(1);
    }

    // Write ciphertext and tag to stdout
    printf("Ciphertext: %s\n", ciphertext);
    printf("Tag: %s\n", ciphertext + ciphertext_len - tag_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}