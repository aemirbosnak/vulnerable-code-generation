//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if user provided correct command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Define input and output file names
    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Define encryption key
    const char *key = argv[3];
    const int key_length = strlen(key);

    // Initialize OpenSSL encryption library
    OpenSSL_add_all_algorithms();

    // Define encryption and decryption contexts
    EVP_CIPHER_CTX *encrypt_ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX *decrypt_ctx = EVP_CIPHER_CTX_new();

    // Define encryption algorithm, key and iv
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    unsigned char *iv = (unsigned char *) EVP_CIPHER_iv_length(cipher);

    // Define input and output buffers
    unsigned char *input_buffer = malloc(BUFFER_SIZE);
    unsigned char *output_buffer = malloc(BUFFER_SIZE + EVP_CIPHER_block_size(cipher));

    // Generate random iv
    RAND_pseudo_bytes(iv, EVP_CIPHER_iv_length(cipher));

    // Initialize encryption context
    EVP_EncryptInit_ex(encrypt_ctx, cipher, NULL, key, iv);

    // Open input and output files
    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");

    // Check if input and output files are successfully opened
    if (!input_fp || !output_fp) {
        fprintf(stderr, "Error: Failed to open input/output file(s).\n");
        return EXIT_FAILURE;
    }

    // Read input data, encrypt it and write to output file
    int bytes_read;
    int bytes_written;
    while ((bytes_read = fread(input_buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        EVP_EncryptUpdate(encrypt_ctx, output_buffer, &bytes_written, input_buffer, bytes_read);
        fwrite(output_buffer, 1, bytes_written, output_fp);
    }

    // Finalize encryption process
    EVP_EncryptFinal_ex(encrypt_ctx, output_buffer, &bytes_written);
    fwrite(output_buffer, 1, bytes_written, output_fp);

    // Clean up encryption resources
    EVP_CIPHER_CTX_free(encrypt_ctx);

    // Flush output buffer and close input/output files
    fflush(output_fp);
    fclose(input_fp);
    fclose(output_fp);

    // Initialize decryption context
    EVP_DecryptInit_ex(decrypt_ctx, cipher, NULL, key, iv);

    // Open input and output files again
    input_fp = fopen(output_file, "rb");
    output_fp = fopen(input_file, "wb");

    // Check if input and output files are successfully opened
    if (!input_fp || !output_fp) {
        fprintf(stderr, "Error: Failed to open input/output file(s).\n");
        return EXIT_FAILURE;
    }

    // Read input data, decrypt it and write to output file
    while ((bytes_read = fread(input_buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        EVP_DecryptUpdate(decrypt_ctx, output_buffer, &bytes_written, input_buffer, bytes_read);
        fwrite(output_buffer, 1, bytes_written, output_fp);
    }

    // Finalize decryption process
    EVP_DecryptFinal_ex(decrypt_ctx, output_buffer, &bytes_written);
    fwrite(output_buffer, 1, bytes_written, output_fp);

    // Clean up decryption resources
    EVP_CIPHER_CTX_free(decrypt_ctx);

    // Free input and output buffers
    free(input_buffer);
    free(output_buffer);

    // Close input/output files
    fclose(input_fp);
    fclose(output_fp);

    printf("File encrypted and decrypted successfully.\n");

    return EXIT_SUCCESS;
}