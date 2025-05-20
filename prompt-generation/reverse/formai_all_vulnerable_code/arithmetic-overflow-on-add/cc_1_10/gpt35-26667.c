//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

/*
This program is a simple implementation of AES encryption using OpenSSL library in C programming language.
*/

void encrypt(char *plaintext, int plaintext_len, char *key, char *iv, char *ciphertext);
void decrypt(char *ciphertext, int ciphertext_len, char *key, char *iv, char *plaintext);

int main(int argc, char *argv[]) {

    /* Get user input */
    char *plaintext = argv[1];
    char *key = argv[2];
    char *iv = argv[3];

    /* Initialize encryption and decryption contexts */
    EVP_CIPHER_CTX *enc_ctx, *dec_ctx;
    enc_ctx = EVP_CIPHER_CTX_new();
    dec_ctx = EVP_CIPHER_CTX_new();

    /* Set up encryption context */
    EVP_EncryptInit_ex(enc_ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Set up decryption context */
    EVP_DecryptInit_ex(dec_ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Calculate ciphertext length */
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;

    /* Allocate memory for ciphertext */
    char *ciphertext = malloc(ciphertext_len);

    /* Encrypt plaintext */
    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    /* Allocate memory for decrypted plaintext */
    char *decrypted_plaintext = malloc(plaintext_len);

    /* Decrypt ciphertext */
    decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    /* Clean up encryption and decryption contexts */
    EVP_CIPHER_CTX_free(enc_ctx);
    EVP_CIPHER_CTX_free(dec_ctx);

    /* Free memory */
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}

void encrypt(char *plaintext, int plaintext_len, char *key, char *iv, char *ciphertext) {

    /* Initialize encryption context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Encrypt plaintext */
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len);
    int ciphertext_len_final;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len_final);

    /* Clean up encryption context */
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(char *ciphertext, int ciphertext_len, char *key, char *iv, char *plaintext) {

    /* Initialize decryption context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Decrypt ciphertext */
    int plaintext_len;
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len);
    int plaintext_len_final;
    EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len_final);

    /* Clean up decryption context */
    EVP_CIPHER_CTX_free(ctx);
    plaintext[plaintext_len + plaintext_len_final] = '\0';
}