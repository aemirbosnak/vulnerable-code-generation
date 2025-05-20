//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <key> <input_file>", argv[0]);
        return 1;
    }
  
    unsigned char *key = (unsigned char *) argv[1];
    FILE *input_file = fopen(argv[2], "r");

    // Determine size of input file
    fseek(input_file, 0L, SEEK_END);
    int file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for input buffer
    unsigned char *input_buffer = (unsigned char *) malloc(file_size);
    fread(input_buffer, sizeof(unsigned char), file_size, input_file);
    fclose(input_file);

    // Initialize AES cipher with input key
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);

    // Allocate memory for output buffer
    unsigned char *output_buffer = (unsigned char *) malloc(file_size + AES_BLOCK_SIZE);

    // Encrypt input buffer and write to output buffer
    int bytes_remaining = file_size;
    unsigned char *input_ptr = input_buffer;
    unsigned char *output_ptr = output_buffer;
    while (bytes_remaining > 0) {
        AES_encrypt(input_ptr, output_ptr, &aes_key);
        input_ptr += AES_BLOCK_SIZE;
        output_ptr += AES_BLOCK_SIZE;
        bytes_remaining -= AES_BLOCK_SIZE;
    }

    // Write encrypted output buffer to file
    char *output_file_name = (char *) malloc(strlen(argv[2] + 4)); // +4 for ".enc" extension
    strncpy(output_file_name, argv[2], strlen(argv[2]));
    strncat(output_file_name, ".enc", 4);
    FILE *output_file = fopen(output_file_name, "w");
    fwrite(output_buffer, sizeof(unsigned char), file_size + AES_BLOCK_SIZE, output_file);
    fclose(output_file);

    printf("Encryption complete. Encrypted file written to %s\n", output_file_name);

    free(input_buffer);
    free(output_buffer);
    free(output_file_name);

    return 0;
}