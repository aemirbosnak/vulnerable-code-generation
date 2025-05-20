//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_KEY_LENGTH 32
#define MAX_IV_LENGTH 16

void handleErrors(void) {
    printf("An error occurred in OpenSSL\n");
    exit(1);
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();

    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();

    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(void) {
    char plaintext[128] = "Hello, World!";
    unsigned char key[MAX_KEY_LENGTH], iv[MAX_IV_LENGTH], ciphertext[128], decryptedtext[128];

    // Generate random key and iv
    if (!RAND_bytes(key, MAX_KEY_LENGTH) || !RAND_bytes(iv, MAX_IV_LENGTH)) {
        handleErrors();
    }

    memset(ciphertext, 0, sizeof(ciphertext));
    encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);

    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, strlen(plaintext));

    memset(decryptedtext, 0, sizeof(decryptedtext));
    decrypt(ciphertext, strlen((const char *)ciphertext), key, iv, decryptedtext);

    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);

    return 0;
}