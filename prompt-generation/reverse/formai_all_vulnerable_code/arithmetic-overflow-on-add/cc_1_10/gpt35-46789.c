//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);
void handleErrors(void);

int main(void) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *plaintext = "This is a secret message!";
    unsigned char key[KEY_SIZE], iv[BLOCK_SIZE], ciphertext[128], decryptedtext[128];
    int ciphertext_len, decryptedtext_len, plaintext_len = strlen(plaintext);

    // Generate random key and IV
    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    // Initialize encryption context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Encrypt plaintext
    if (encrypt(plaintext, plaintext_len, key, iv, ciphertext)) {
        printf("Original message: %s\n", plaintext);
        printf("Encrypted message: ");
        for (int i = 0; i < ciphertext_len; i++) printf("%02x", ciphertext[i]);
        printf("\n");

        // Initialize decryption context
        if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

        // Decrypt ciphertext
        if (decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext)) {
            printf("Decrypted message: %s\n", decryptedtext);
        }
    }

    return 0;
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len, ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len, plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

void handleErrors(void) {
    printf("Error occurred\n");
    exit(1);
}