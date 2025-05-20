//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(const char *plaintext, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, (unsigned char *)plaintext, strlen(plaintext))) handleErrors();

    int len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len)) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len)) handleErrors();

    int len;
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len)) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void printHex(const unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main(void) {
    // Initialize Key and IV
    unsigned char key[32] = "0123456789abcdef0123456789abcdef"; // 32 bytes for AES-256
    unsigned char iv[16] = "0123456789abcdef"; // 16 bytes for AES block size

    // Input plaintext
    char plaintext[BUF_SIZE];
    printf("Enter plaintext (max 1024 characters): ");
    fgets(plaintext, BUF_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline at the end

    unsigned char ciphertext[BUF_SIZE + EVP_MAX_BLOCK_LENGTH];
    int ciphertext_len;

    // Encrypting the plaintext
    encrypt(plaintext, key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext (hex): ");
    printHex(ciphertext, ciphertext_len);

    unsigned char decryptedtext[BUF_SIZE];
    int decryptedtext_len;

    // Decrypting the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}