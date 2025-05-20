//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define ERROR_SIZE 1024

int main(int argc, char** argv) {
    /* Input parameters */
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [encrypt|decrypt] <key>\n", argv[0]);
        exit(1);
    }
    const char *operation = argv[1];
    const char *key = argv[2];
    size_t key_length = strlen(key);

    /* Initialize OpenSSL */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "OpenSSL initialization error\n");
        exit(1);
    }

    /* Cipher parameters */
    const EVP_CIPHER *cipher_type = EVP_aes_128_ecb();  // Using AES-128 in ECB mode
    const int BLOCK_SIZE = EVP_CIPHER_block_size(cipher_type);
    unsigned char iv[BLOCK_SIZE];
    memset(iv, 0, BLOCK_SIZE);
    unsigned char *plaintext = NULL;
    unsigned char *ciphertext = NULL;
    int plaintext_length = 0;
    int ciphertext_length = 0;
    int output_length = 0;

    if (strcmp(operation, "encrypt") == 0) {
        /* Get plaintext */
        fprintf(stdout, "Enter plaintext: ");
        size_t line_length = 0;
        ssize_t bytes_read = getline(&plaintext, &line_length, stdin);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading plaintext\n");
            exit(1);
        }
        plaintext_length = bytes_read - 1;  // Remove newline character

        /* Allocate memory for ciphertext */
        ciphertext_length = plaintext_length + BLOCK_SIZE;
        ciphertext = (unsigned char*)malloc(ciphertext_length);
        if (ciphertext == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }

        /* Encrypt plaintext */
        if (!EVP_EncryptInit_ex(ctx, cipher_type, NULL, (const unsigned char*)key, iv)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Encryption initialization error: %s\n", error);
            exit(1);
        }
        if (!EVP_EncryptUpdate(ctx, ciphertext, &output_length, plaintext, plaintext_length)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Encryption error: %s\n", error);
            exit(1);
        }
        ciphertext_length = output_length;
        if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &output_length)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Encryption finalization error: %s\n", error);
            exit(1);
        }
        ciphertext_length += output_length;

        /* Print ciphertext */
        fprintf(stdout, "Ciphertext: ");
        for (int i = 0; i < ciphertext_length; i++) {
            fprintf(stdout, "%02X", ciphertext[i]);
        }
        fprintf(stdout, "\n");

    } else if (strcmp(operation, "decrypt") == 0) {
        /* Get ciphertext */
        fprintf(stdout, "Enter ciphertext: ");
        size_t line_length = 0;
        ssize_t bytes_read = getline(&plaintext, &line_length, stdin);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading ciphertext\n");
            exit(1);
        }
        plaintext_length = bytes_read - 1;  // Remove newline character

        /* Allocate memory for ciphertext */
        ciphertext_length = plaintext_length / 2;
        ciphertext = (unsigned char*)malloc(ciphertext_length);
        if (ciphertext == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }

        /* Convert hex string to bytes */
        char hex_byte[3] = "";
        for (int i = 0; i < plaintext_length; i += 2) {
            strncpy(hex_byte, plaintext + i, 2);
            ciphertext[i / 2] = (unsigned char)strtol(hex_byte, NULL, 16);
        }

        /* Decrypt ciphertext */
        if (!EVP_DecryptInit_ex(ctx, cipher_type, NULL, (const unsigned char*)key, iv)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Decryption initialization error: %s\n", error);
            exit(1);
        }
        if (!EVP_DecryptUpdate(ctx, plaintext, &output_length, ciphertext, ciphertext_length)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Decryption error: %s\n", error);
            exit(1);
        }
        plaintext_length = output_length;
        if (!EVP_DecryptFinal_ex(ctx, plaintext + plaintext_length, &output_length)) {
            char error[ERROR_SIZE];
            ERR_error_string(ERR_get_error(), error);
            fprintf(stderr, "Decryption finalization error: %s\n", error);
            exit(1);
        }
        plaintext_length += output_length;

        /* Print plaintext */
        fprintf(stdout, "Plaintext: %s", plaintext);

    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        exit(1);
    }

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);
    free(plaintext);
    free(ciphertext);

    return 0;
}