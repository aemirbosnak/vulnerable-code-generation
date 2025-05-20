//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: dynamic
/*
 * File Encyptor
 *
 * This program takes a file as input, encrypts it using the Caesar cipher,
 * and then writes the encrypted data to a new file.
 *
 * Usage:
 *   ./file_encyptor <input_file> <output_file> <key>
 *
 * where:
 *   <input_file> is the file to be encrypted
 *   <output_file> is the file where the encrypted data will be written
 *   <key> is the encryption key
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    // Open the output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Get the encryption key
    int key = atoi(argv[3]);

    // Encrypt the file
    char buffer[BUFSIZ];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFSIZ, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = (buffer[i] + key) % 256;
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}