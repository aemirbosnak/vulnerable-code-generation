//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len)) handleErrors();

    int len;
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len)) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len)) handleErrors();

    int len;
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len)) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(void) {
    unsigned char key[32]; // 256-bit key
    unsigned char iv[16];  // AES block size

    // Generate random key and IV
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Error generating random bytes.\n");
        return 1;
    }

    unsigned char plaintext[] = "Alan Turing invented the concept of a programmable computer.";
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    int decryptedtext_len, ciphertext_len;

    printf("Original Plaintext: %s\n", plaintext);
    ciphertext_len = sizeof(ciphertext);
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext (hex): ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    decryptedtext_len = sizeof(decryptedtext);
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null terminate the string

    printf("Decrypted Plaintext: %s\n", decryptedtext);
    
    // Clean up, clear the key and data from memory
    OPENSSL_cleanse(key, sizeof(key));
    OPENSSL_cleanse(iv, sizeof(iv));
    OPENSSL_cleanse(ciphertext, sizeof(ciphertext));
    OPENSSL_cleanse(decryptedtext, sizeof(decryptedtext));

    return 0;
}