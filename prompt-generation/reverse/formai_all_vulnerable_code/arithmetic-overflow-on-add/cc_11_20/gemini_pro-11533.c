//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>

int main() {
    // 3DES Encryption with CBC (Cipher Block Chaining) Mode
    // Key and IV must be 24 bytes each
    char *key = "0123456789abcdefghij";
    char *iv = "0123456789abcdefghij";
    unsigned char *plaintext = "This is plaintext to be encrypted";

    // Initialize encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        perror("EVP_CIPHER_CTX_new failed");
        return EXIT_FAILURE;
    }

    // Initialize the cipher for encryption with the given key and IV
    if (EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, (unsigned char *)key, (unsigned char *)iv) != 1) {
        perror("EVP_EncryptInit_ex failed");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Update encryption context with plaintext
    int plaintext_len = strlen((char *)plaintext);
    int ciphertext_len = plaintext_len + EVP_CIPHER_CTX_block_size(ctx);
    unsigned char *ciphertext = malloc(ciphertext_len);
    if (!ciphertext) {
        perror("malloc failed");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }
    int ciphertext_out_len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_out_len, (unsigned char *)plaintext, plaintext_len) != 1) {
        perror("EVP_EncryptUpdate failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return EXIT_FAILURE;
    }

    // Finalize encryption and get the remaining ciphertext
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_out_len, &ciphertext_out_len) != 1) {
        perror("EVP_EncryptFinal_ex failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return EXIT_FAILURE;
    }
    ciphertext_len = ciphertext_out_len;

    // Print ciphertext in hexadecimal format
    printf("Ciphertext (hex): ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decryption
    // Initialize decryption context
    if (EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, (unsigned char *)key, (unsigned char *)iv) != 1) {
        perror("EVP_DecryptInit_ex failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return EXIT_FAILURE;
    }

    // Update decryption context with ciphertext
    int decryptedtext_len = ciphertext_len;
    unsigned char *decryptedtext = malloc(decryptedtext_len);
    if (!decryptedtext) {
        perror("malloc failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return EXIT_FAILURE;
    }
    int decryptedtext_out_len;
    if (EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_out_len, ciphertext, ciphertext_len) != 1) {
        perror("EVP_DecryptUpdate failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        free(decryptedtext);
        return EXIT_FAILURE;
    }

    // Finalize decryption and get the remaining plaintext
    if (EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_out_len, &decryptedtext_out_len) != 1) {
        perror("EVP_DecryptFinal_ex failed");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        free(decryptedtext);
        return EXIT_FAILURE;
    }
    decryptedtext_len = decryptedtext_out_len;

    // Print plaintext
    printf("Decrypted plaintext: %s\n", decryptedtext);

    // Free memory
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);
    free(decryptedtext);

    return EXIT_SUCCESS;
}