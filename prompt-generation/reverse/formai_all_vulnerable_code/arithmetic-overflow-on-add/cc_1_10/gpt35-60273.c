//FormAI DATASET v1.0 Category: modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>

#define AES_BLOCK_SIZE 16
#define KEY_SIZE 32

void print_hex(const unsigned char *array, size_t len) {
    for (size_t i = 0; i < len; ++i)
        printf("%02x", array[i]);
    putchar('\n');
}

void encrypt_aes_256(const unsigned char *plaintext, size_t plaintext_len, const unsigned char *key, unsigned char *ciphertext) {
    uint8_t iv[EVP_MAX_IV_LENGTH] = {0};
    EVP_CIPHER_CTX *ctx;
    int len, len1, len2;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        abort();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        abort();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len1, plaintext, plaintext_len))
        abort();

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len1, &len2))
        abort();

    len = len1 + len2;
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    char plaintext[1024] = "This is a secret message!";
    unsigned char key[KEY_SIZE] = "12345678901234567890123456789012";
    unsigned char ciphertext[1024 + AES_BLOCK_SIZE] = {0};

    printf("Original message:\n%s\n", plaintext);

    size_t plaintext_len = strlen(plaintext);
    encrypt_aes_256((unsigned char*)plaintext, plaintext_len, key, ciphertext);

    printf("Encrypted message (hex):\n");
    print_hex(ciphertext, plaintext_len);

    return 0;
}