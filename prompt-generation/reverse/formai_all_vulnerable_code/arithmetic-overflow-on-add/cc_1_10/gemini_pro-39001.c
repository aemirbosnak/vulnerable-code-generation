//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

/* Function to print errors */
void print_errors() {
    unsigned long err;
    while ((err = ERR_get_error()) != 0) {
        fprintf(stderr, "%s\n", ERR_error_string(err, NULL));
    }
}

/* Function to encrypt data */
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char **ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    int status;

    // Create a new context for encryption
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        print_errors();
        return -1;
    }

    // Initialize the context for encryption
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Calculate the ciphertext length
    *ciphertext_len = plaintext_len + EVP_CIPHER_CTX_block_size(ctx);

    // Allocate memory for the ciphertext
    *ciphertext = (unsigned char *)malloc(*ciphertext_len);
    if (*ciphertext == NULL) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Encrypt the plaintext
    if (!EVP_EncryptUpdate(ctx, *ciphertext, ciphertext_len, plaintext, plaintext_len)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return -1;
    }

    // Finalize the encryption
    if (!EVP_EncryptFinal_ex(ctx, *ciphertext + *ciphertext_len, ciphertext_len)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        free(*ciphertext);
        return -1;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

/* Function to decrypt data */
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char **plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;
    int status;

    // Create a new context for decryption
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        print_errors();
        return -1;
    }

    // Initialize the context for decryption
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Calculate the plaintext length
    *plaintext_len = ciphertext_len - EVP_CIPHER_CTX_block_size(ctx);

    // Allocate memory for the plaintext
    *plaintext = (unsigned char *)malloc(*plaintext_len);
    if (*plaintext == NULL) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Decrypt the ciphertext
    if (!EVP_DecryptUpdate(ctx, *plaintext, plaintext_len, ciphertext, ciphertext_len)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return -1;
    }

    // Finalize the decryption
    if (!EVP_DecryptFinal_ex(ctx, *plaintext + *plaintext_len, plaintext_len)) {
        print_errors();
        EVP_CIPHER_CTX_free(ctx);
        free(*plaintext);
        return -1;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

int main() {
    // The plaintext to encrypt
    unsigned char plaintext[] = "Hello, world!";

    // The key to use for encryption
    unsigned char key[] = "12345678901234567890123456789012";

    // The initialization vector to use for encryption
    unsigned char iv[] = "0123456789012345";

    // The encrypted ciphertext
    unsigned char *ciphertext;

    // The length of the ciphertext
    int ciphertext_len;

    // Encrypt the plaintext
    if (encrypt(plaintext, strlen(plaintext), key, iv, &ciphertext, &ciphertext_len) != 0) {
        fprintf(stderr, "Error encrypting plaintext\n");
        return EXIT_FAILURE;
    }

    // Decrypt the ciphertext
    unsigned char *plaintext2;
    int plaintext2_len;
    if (decrypt(ciphertext, ciphertext_len, key, iv, &plaintext2, &plaintext2_len) != 0) {
        fprintf(stderr, "Error decrypting ciphertext\n");
        return EXIT_FAILURE;
    }

    // Compare the original plaintext with the decrypted plaintext
    if (memcmp(plaintext, plaintext2, strlen(plaintext)) != 0) {
        fprintf(stderr, "Error: decrypted plaintext does not match original plaintext\n");
        return EXIT_FAILURE;
    }

    // Clean up
    free(ciphertext);
    free(plaintext2);

    return EXIT_SUCCESS;
}