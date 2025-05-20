//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: optimized
/*
 * File Encryptor
 *
 * This program takes a file as input, encrypts it using a simple XOR encryption
 * method, and writes the encrypted data to a new file.
 *
 * Usage:
 *   file_encryptor <input file> <output file> <key>
 *
 * Example:
 *   file_encryptor input.txt output.txt 12345678
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: unable to open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fprintf(stderr, "Error: unable to open output file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    int key = atoi(argv[3]);
    if (key <= 0) {
        fprintf(stderr, "Error: invalid key %s\n", argv[3]);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char buffer[1024];
    size_t buffer_size = sizeof(buffer);
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, buffer_size, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}