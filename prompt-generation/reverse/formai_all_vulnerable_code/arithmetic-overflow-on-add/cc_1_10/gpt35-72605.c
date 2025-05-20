//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void handleErrors(void);
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext);

int main() {

    char *plaintext = "This is a secret message.";
    char *key_str = "secretkey123";
    unsigned char iv[BLOCK_SIZE] = {0};
    unsigned char ciphertext[256] = {0};
    unsigned char decryptedtext[256] = {0};
    unsigned char key[KEY_SIZE];

    // Generate random key
    if (!RAND_bytes(key, KEY_SIZE)) {
        fprintf(stderr, "Error generating random key.\n");
        exit(1);
    }

    int ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    printf("Original plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext) {

    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext) {

    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}