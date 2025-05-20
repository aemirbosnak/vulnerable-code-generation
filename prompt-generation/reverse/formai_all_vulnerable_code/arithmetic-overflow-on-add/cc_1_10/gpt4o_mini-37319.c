//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256
#define AES_BLOCK_SIZE 128
#define BUFFER_SIZE 1024

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, 
             unsigned char *key, unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len))
        handleErrors();

    int len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len))
        handleErrors();

    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len,
             unsigned char *key, unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len))
        handleErrors();

    int len;
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len))
        handleErrors();

    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8))
        handleErrors();
    if (!RAND_bytes(iv, AES_BLOCK_SIZE / 8))
        handleErrors();
}

int main() {
    unsigned char key[AES_KEY_SIZE / 8];
    unsigned char iv[AES_BLOCK_SIZE / 8];
    unsigned char *plaintext = (unsigned char *)"This is a secret message.";
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];
    int decryptedtext_len, ciphertext_len;

    generate_key_and_iv(key, iv);

    printf("Original plaintext: %s\n", plaintext);

    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext (Hex): ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}