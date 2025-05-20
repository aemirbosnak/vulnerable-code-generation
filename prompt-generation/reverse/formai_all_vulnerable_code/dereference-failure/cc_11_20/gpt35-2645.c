//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE_AES_128 16
#define KEY_SIZE_AES_192 24
#define KEY_SIZE_AES_256 32
#define BLOCK_SIZE_AES_128 16
#define BLOCK_SIZE_AES_192 24
#define BLOCK_SIZE_AES_256 32

int main(int argc, char *argv[])
{
    AES_KEY aes_key;
    unsigned char key[32];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char indata[1024];
    unsigned char outdata[1024];
    int bytes_read, bytes_written;
    int key_size = KEY_SIZE_AES_256;
    int block_size = BLOCK_SIZE_AES_256;

    if (argc < 4) {
        printf("Usage: %s [encrypt|decrypt] [key] [input_file] [output_file] [optional_block_size]\n", argv[0]);
        return 1;
    }

    // Initialize key
    memset(key, 0x00, sizeof(key));
    strncpy(key, argv[2], key_size);

    // Initialize IV
    memset(iv, 0x00, sizeof(iv));

    // Initialize AES key
    if (AES_set_encrypt_key(key, key_size*8, &aes_key) < 0) {
        printf("Error initializing AES key\n");
        return 1;
    }

    // Check if block size argument was provided
    if (argc > 5) {
        block_size = atoi(argv[5]);
    }

    // Open input file
    FILE *input_file = fopen(argv[3], "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Open output file
    FILE *output_file = fopen(argv[4], "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Encrypt or decrypt file
    if (strncmp(argv[1], "encrypt", 7) == 0) {
        // Encrypt file
        while (1) {
            bytes_read = fread(indata, 1, block_size, input_file);
            AES_cbc_encrypt(indata, outdata, bytes_read, &aes_key, iv, AES_ENCRYPT);
            bytes_written = fwrite(outdata, 1, bytes_read, output_file);
            if (bytes_read < block_size) break;
        }
    } else if (strncmp(argv[1], "decrypt", 7) == 0) {
        // Decrypt file
        while (1) {
            bytes_read = fread(indata, 1, block_size, input_file);
            AES_cbc_encrypt(indata, outdata, bytes_read, &aes_key, iv, AES_DECRYPT);
            bytes_written = fwrite(outdata, 1, bytes_read, output_file);
            if (bytes_read < block_size) break;
        }
    } else {
        printf("Invalid command option\n");
        return 1;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}