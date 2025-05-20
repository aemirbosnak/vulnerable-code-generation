//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024

void encrypt(char* input, char* key) {
    EVP_CIPHER_CTX* ctx;
    int len;
    unsigned char* ciphertext;

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
    EVP_EncryptUpdate(ctx, ciphertext, &len, input, strlen(input));
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    EVP_CIPHER_CTX_free(ctx);

    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    free(ciphertext);
}

void decrypt(char* ciphertext, char* key) {
    EVP_CIPHER_CTX* ctx;
    int len;
    unsigned char* plaintext;

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, strlen(ciphertext));
    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    EVP_CIPHER_CTX_free(ctx);

    printf("Plaintext: ");
    for (int i = 0; i < len; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    free(plaintext);
}

int main() {
    char input[BUFFER_SIZE] = "This is a test message";
    char key[BUFFER_SIZE] = "12345678901234567890123456789012";
    char ciphertext[BUFFER_SIZE];

    encrypt(input, key);
    decrypt(ciphertext, key);

    return 0;
}