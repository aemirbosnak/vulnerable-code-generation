//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Main function
int main(int argc, char* argv[]) {
    // Check if the user provided enough arguments
    if (argc < 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    // Create an SHA-256 context
    EVP_MD_CTX* md_ctx = EVP_MD_CTX_new();
    if (md_ctx == NULL) {
        printf("Could not create MD context\n");
        return 1;
    }

    // Initialize the context for SHA-256
    if (EVP_DigestInit_ex(md_ctx, EVP_sha256(), NULL) != 1) {
        printf("Could not initialize SHA-256 context\n");
        return 1;
    }

    // Open the input file
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for the input buffer
    unsigned char* input_buffer = malloc(EVP_MAX_BLOCK_LENGTH);
    if (input_buffer == NULL) {
        printf("Could not allocate memory for input buffer\n");
        return 1;
    }

    // Read the input file block by block and update the context
    int bytes_read = 0;
    while ((bytes_read = fread(input_buffer, 1, EVP_MAX_BLOCK_LENGTH, input_file)) > 0) {
        if (EVP_DigestUpdate(md_ctx, input_buffer, bytes_read) != 1) {
            printf("Could not update SHA-256 context\n");
            return 1;
        }
    }

    // Finalize the context and get the SHA-256 hash
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_length = 0;
    if (EVP_DigestFinal_ex(md_ctx, hash, &hash_length) != 1) {
        printf("Could not finalize SHA-256 context\n");
        return 1;
    }

    // Close the input file and free the input buffer
    fclose(input_file);
    free(input_buffer);

    // Open the output file for writing
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Could not open file %s\n", argv[2]);
        return 1;
    }

    // Write the SHA-256 hash to the output file
    if (fwrite(hash, 1, hash_length, output_file) != hash_length) {
        printf("Could not write hash to output file\n");
        return 1;
    }

    // Close the output file
    fclose(output_file);

    // Free the context
    EVP_MD_CTX_free(md_ctx);

    return 0;
}