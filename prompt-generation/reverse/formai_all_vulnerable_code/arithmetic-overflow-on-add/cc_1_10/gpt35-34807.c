//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void print_hex(unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

void handle_errors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int main(void) {
    // Declare variables
    char plaintext[] = "Hello, world!";
    unsigned char key[32] = "secret_key";
    unsigned char iv[16] = "initialization_v";
    unsigned char ciphertext[1024];
    unsigned char decryptedtext[1024];
    int len = strlen(plaintext);

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Create and initialize cipher context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handle_errors();
    }

    // Initialize encryption operation with AES-256-CBC algorithm
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        handle_errors();
    }

    // Encrypt plaintext to ciphertext
    int ciphertext_len, decryptedtext_len;
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *) plaintext, len)) {
        handle_errors();
    }

    // Finalize encryption operation
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &len)) {
        handle_errors();
    }
    ciphertext_len += len;

    printf("Ciphertext: ");
    print_hex(ciphertext, ciphertext_len);

    // Initialize decryption operation
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        handle_errors();
    }

    // Decrypt ciphertext to plaintext
    if (1 != EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len)) {
        handle_errors();
    }

    // Finalize decryption operation
    if (1 != EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &len)) {
        handle_errors();
    }
    decryptedtext_len += len;

    printf("Plaintext: %s\n", decryptedtext);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_free_strings();

    return 0;
}