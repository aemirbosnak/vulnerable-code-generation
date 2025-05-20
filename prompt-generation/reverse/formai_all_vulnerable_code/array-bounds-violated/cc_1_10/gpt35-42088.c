//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16

void handleErrors(void);

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext);

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext);

int main(int argc, char *argv[]) {
    // Generate a random key and IV using OpenSSL's PRNG
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[BLOCK_SIZE];
    if (RAND_bytes(key, EVP_MAX_KEY_LENGTH) != 1) {
        handleErrors();
    }
    if (RAND_bytes(iv, BLOCK_SIZE) != 1) {
        handleErrors();
    }

    // Plaintext message to be encrypted
    unsigned char *plaintext = (unsigned char *) "This is a test message.";
    int plaintext_len = strlen((char *) plaintext);

    // Buffer for ciphertext and decrypted plaintext
    unsigned char ciphertext[1024];
    unsigned char decrypted_plaintext[1024];

    // Encrypt the plaintext message
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the ciphertext
    printf("Ciphertext:\n");
    BIO_dump_fp(stdout, (const char *) ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    int decrypted_plaintext_len = decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);
    decrypted_plaintext[decrypted_plaintext_len] = '\0';

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        handleErrors();
    }
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) {
        handleErrors();
    }
    ciphertext_len = len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        handleErrors();
    }
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    int ret;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        handleErrors();
    }
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) {
        handleErrors();
    }
    plaintext_len = len;
    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    if (ret == 0) {
        handleErrors();
    }
    return plaintext_len;
}