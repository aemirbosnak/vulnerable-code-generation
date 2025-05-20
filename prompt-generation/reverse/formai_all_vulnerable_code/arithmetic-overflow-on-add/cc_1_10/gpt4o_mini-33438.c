//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // AES-256
#define AES_BLOCK_SIZE 16   // Block size for AES
#define MAX_BUFFER_SIZE 1024 // Max buffer size for plaintext

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    int len;
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    *ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    int len;
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    *plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (RAND_bytes(key, AES_KEY_LENGTH / 8) != 1 || 
        RAND_bytes(iv, AES_BLOCK_SIZE) != 1) {
        fprintf(stderr, "Could not generate random key or IV\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];  // AES key
    unsigned char iv[AES_BLOCK_SIZE];        // Initialization vector
    unsigned char plaintext[MAX_BUFFER_SIZE]; // Buffer for plaintext
    unsigned char ciphertext[MAX_BUFFER_SIZE + AES_BLOCK_SIZE]; // Buffer for ciphertext
    unsigned char decryptedtext[MAX_BUFFER_SIZE]; // Buffer for decrypted text

    generate_key_and_iv(key, iv);

    printf("Enter plaintext to encrypt: ");
    if (fgets((char *)plaintext, MAX_BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        exit(EXIT_FAILURE);
    }
    
    // Remove newline character from input
    size_t len = strlen((char *)plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    int ciphertext_len;
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    int decryptedtext_len;
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}