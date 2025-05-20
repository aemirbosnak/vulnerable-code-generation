//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 32 // 256-bit
#define AES_BLOCK_SIZE 16 // AES block size

// Function to generate a random IV
void generate_iv(unsigned char *iv) {
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        fprintf(stderr, "Error generating random IV\n");
        exit(EXIT_FAILURE);
    }
}

// Function to encrypt plaintext using AES-256-CBC
int encrypt(const unsigned char *plaintext, int plaintext_len, 
            const unsigned char *key, unsigned char *iv, 
            unsigned char **ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error initializing cipher context\n");
        return -1;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    *ciphertext = (unsigned char *)malloc(plaintext_len + AES_BLOCK_SIZE);
    if (*ciphertext == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    if (EVP_EncryptUpdate(ctx, *ciphertext, &len, plaintext, plaintext_len) != 1) {
        fprintf(stderr, "Error during encryption update\n");
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return -1;
    }
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, *ciphertext + len, &len) != 1) {
        fprintf(stderr, "Error during final encryption step\n");
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return -1;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

// Function to decrypt ciphertext using AES-256-CBC
int decrypt(const unsigned char *ciphertext, int ciphertext_len, 
            const unsigned char *key, unsigned char *iv, 
            unsigned char **plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error initializing cipher context\n");
        return -1;
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing decryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    *plaintext = (unsigned char *)malloc(ciphertext_len);
    if (*plaintext == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    if (EVP_DecryptUpdate(ctx, *plaintext, &len, ciphertext, ciphertext_len) != 1) {
        fprintf(stderr, "Error during decryption update\n");
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return -1;
    }
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, *plaintext + len, &len) != 1) {
        fprintf(stderr, "Error during final decryption step\n");
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return -1;
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

// Function to print data in hexadecimal format
void print_hex(const unsigned char *data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    // Sample input data
    const unsigned char *key = (unsigned char *)"0123456789abcdef0123456789abcdef"; // 32 bytes for AES-256
    const unsigned char *plaintext = (unsigned char *)"Hello, this is a secret message!";
    
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char *ciphertext = NULL;
    unsigned char *decryptedtext = NULL;

    // Generate random IV
    generate_iv(iv);

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, &ciphertext);
    
    // Output encrypted data
    printf("Ciphertext:\n");
    print_hex(ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, &decryptedtext);
    
    // Output decrypted data
    printf("Decrypted text: %.*s\n", decryptedtext_len, decryptedtext);

    // Free allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}