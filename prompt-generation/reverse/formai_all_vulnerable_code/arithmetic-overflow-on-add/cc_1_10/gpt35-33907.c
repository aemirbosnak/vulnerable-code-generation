//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <key> <iv> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *key = argv[1];
    const char *iv = argv[2];
    const char *input_file = argv[3];
    const char *output_file = argv[4];

    // Initialize the cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Error initializing cipher context.\n");
        return EXIT_FAILURE;
    }

    // Set the cipher type and mode
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char *) key, (const unsigned char *) iv) != 1) {
        printf("Error setting cipher type and mode.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Open the input and output files
    FILE *in_fp = fopen(input_file, "rb");
    if (in_fp == NULL) {
        printf("Error opening input file.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    FILE *out_fp = fopen(output_file, "wb");
    if (out_fp == NULL) {
        printf("Error opening output file.\n");
        fclose(in_fp);
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Encrypt the input file and write to the output file
    int bytes_read, bytes_written, total_written = 0;
    unsigned char in_buf[BUF_SIZE], out_buf[BUF_SIZE + EVP_MAX_BLOCK_LENGTH];
    while ((bytes_read = fread(in_buf, 1, BUF_SIZE, in_fp)) > 0) {
        if (EVP_EncryptUpdate(ctx, out_buf, &bytes_written, in_buf, bytes_read) != 1) {
            printf("Error encrypting data.\n");
            fclose(out_fp);
            fclose(in_fp);
            EVP_CIPHER_CTX_free(ctx);
            return EXIT_FAILURE;
        }
        total_written += bytes_written;
        fwrite(out_buf, 1, bytes_written, out_fp);
    }

    if (EVP_EncryptFinal_ex(ctx, out_buf, &bytes_written) != 1) {
        printf("Error finalizing encryption.\n");
        fclose(out_fp);
        fclose(in_fp);
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }
    total_written += bytes_written;
    fwrite(out_buf, 1, bytes_written, out_fp);

    // Close the files and free the cipher context
    fclose(out_fp);
    fclose(in_fp);
    EVP_CIPHER_CTX_free(ctx);

    printf("Encryption complete. %d bytes written to %s.\n", total_written, output_file);
    return EXIT_SUCCESS;
}