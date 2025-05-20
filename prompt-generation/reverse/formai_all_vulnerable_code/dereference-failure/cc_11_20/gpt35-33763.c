//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[])
{
    // Handle program arguments
    if (argc < 3) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    const char *algorithm = "aes-256-cbc";
    const char *key = "myencryptionkey123"; // Secret key
    const char *iv = "myiv456"; // Initialization vector
    const int key_len = strlen(key);
    const int iv_len = strlen(iv);
    unsigned char key_buffer[key_len];
    unsigned char iv_buffer[iv_len];
    memcpy(key_buffer, key, key_len);
    memcpy(iv_buffer, iv, iv_len);

    // Load algorithm
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("ERROR: Failed to create EVP_CIPHER_CTX\n");
        return 1;
    }
    const EVP_CIPHER *cipher = EVP_get_cipherbyname(algorithm);
    if (cipher == NULL) {
        printf("ERROR: Unknown algorithm: %s\n", algorithm);
        return 1;
    }

    // Initialize context
    if (EVP_CipherInit_ex(ctx, cipher, NULL, key_buffer, iv_buffer, argv[1][0] == 'e' ? 1 : 0) != 1) {
        printf("ERROR: EVP_CipherInit_ex failed\n");
        return 1;
    }

    // Open files
    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        printf("ERROR: Failed to open input file\n");
        return 1;
    }
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("ERROR: Failed to open output file\n");
        return 1;
    }

    // Encrypt or decrypt data
    unsigned char input_data[1024];
    unsigned char output_data[1024 + EVP_MAX_BLOCK_LENGTH];
    int bytes_read = 0;
    int bytes_written = 0;
    while ((bytes_read = fread(input_data, 1, sizeof(input_data), input_file)) != 0) {
        if (EVP_CipherUpdate(ctx, output_data, &bytes_written, input_data, bytes_read) == 0) {
            printf("ERROR: EVP_CipherUpdate failed\n");
            return 1;
        }
        fwrite(output_data, 1, bytes_written, output_file);
    }
    if (EVP_CipherFinal_ex(ctx, output_data, &bytes_written) == 0) {
        printf("ERROR: EVP_CipherFinal_ex failed\n");
        return 1;
    }
    fwrite(output_data, 1, bytes_written, output_file);

    // Clean up
    fclose(input_file);
    fclose(output_file);
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}