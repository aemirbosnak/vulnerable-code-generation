//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define AES_KEY_LENGTH 256
#define AES_BLOCK_SIZE 16

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len) != 1) handleErrors();

    int len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len) != 1) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len) != 1) handleErrors();

    int len;
    if (EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len) != 1) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (RAND_bytes(key, AES_KEY_LENGTH / 8) != 1) {
        handleErrors();
    }
    if (RAND_bytes(iv, AES_BLOCK_SIZE) != 1) {
        handleErrors();
    }
}

void print_hex(const char *label, unsigned char *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main(void) {
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char *plaintext = (unsigned char *)"Hello, this is a test message!";
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    int decryptedtext_len, ciphertext_len;

    generate_key_iv(key, iv);

    printf("Original Plaintext: %s\n", plaintext);

    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    print_hex("Ciphertext", ciphertext, ciphertext_len);

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string
    
    printf("Decrypted Plaintext: %s\n", decryptedtext);

    return 0;
}