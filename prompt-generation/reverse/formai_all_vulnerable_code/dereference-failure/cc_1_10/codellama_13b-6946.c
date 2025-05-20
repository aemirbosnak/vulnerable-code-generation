//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: secure
/*
 * File Encryptor
 *
 * Usage: ./file_encryptor <input_file> <output_file>
 *
 * Example: ./file_encryptor input.txt output.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>
#include <openssl/evp.h>

// Global variables
static const uint8_t key[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
static const uint8_t iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

// Function prototypes
void handle_args(int argc, char **argv);
void encrypt_file(const char *input_file, const char *output_file);

int main(int argc, char **argv) {
    handle_args(argc, argv);
    return 0;
}

void handle_args(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }
    encrypt_file(argv[1], argv[2]);
}

void encrypt_file(const char *input_file, const char *output_file) {
    // Open input file
    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) {
        perror("Error opening input file");
        exit(1);
    }

    // Open output file
    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) {
        perror("Error opening output file");
        exit(1);
    }

    // Initialize encryption context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error creating encryption context\n");
        exit(1);
    }

    // Initialize encryption key and IV
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error initializing encryption context\n");
        exit(1);
    }

    // Encrypt file
    uint8_t in_buf[16];
    uint8_t out_buf[16];
    size_t in_len, out_len;
    while (1) {
        // Read input file
        in_len = fread(in_buf, 1, 16, in_file);
        if (ferror(in_file)) {
            fprintf(stderr, "Error reading input file\n");
            exit(1);
        }

        // Encrypt data
        if (1 != EVP_EncryptUpdate(ctx, out_buf, &out_len, in_buf, in_len)) {
            fprintf(stderr, "Error encrypting data\n");
            exit(1);
        }

        // Write encrypted data to output file
        fwrite(out_buf, 1, out_len, out_file);
        if (ferror(out_file)) {
            fprintf(stderr, "Error writing to output file\n");
            exit(1);
        }

        // Check if end of file
        if (feof(in_file)) {
            break;
        }
    }

    // Finalize encryption
    if (1 != EVP_EncryptFinal_ex(ctx, out_buf, &out_len)) {
        fprintf(stderr, "Error finalizing encryption\n");
        exit(1);
    }

    // Write final block to output file
    fwrite(out_buf, 1, out_len, out_file);
    if (ferror(out_file)) {
        fprintf(stderr, "Error writing final block to output file\n");
        exit(1);
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    fclose(in_file);
    fclose(out_file);
}