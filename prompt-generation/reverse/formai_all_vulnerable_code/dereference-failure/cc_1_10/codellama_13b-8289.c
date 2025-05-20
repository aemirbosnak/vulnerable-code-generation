//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define KEY_SIZE 32
#define FILENAME_SIZE 256

bool encrypt_file(const char *input_filename, const char *output_filename, const uint8_t *key, size_t key_size) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return false;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file);
        return false;
    }

    // Read the input file and write the encrypted output to the output file
    uint8_t buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_size];
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return true;
}

bool decrypt_file(const char *input_filename, const char *output_filename, const uint8_t *key, size_t key_size) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return false;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file);
        return false;
    }

    // Read the input file and write the decrypted output to the output file
    uint8_t buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_size];
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return true;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    // Get the input and output file names
    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    // Get the key
    uint8_t key[KEY_SIZE];
    for (size_t i = 0; i < KEY_SIZE; i++) {
        key[i] = (uint8_t)atoi(argv[3][i]);
    }

    // Encrypt the file
    bool success = encrypt_file(input_filename, output_filename, key, KEY_SIZE);
    if (!success) {
        fprintf(stderr, "Error encrypting file\n");
        return 1;
    }

    // Decrypt the file
    success = decrypt_file(output_filename, input_filename, key, KEY_SIZE);
    if (!success) {
        fprintf(stderr, "Error decrypting file\n");
        return 1;
    }

    return 0;
}