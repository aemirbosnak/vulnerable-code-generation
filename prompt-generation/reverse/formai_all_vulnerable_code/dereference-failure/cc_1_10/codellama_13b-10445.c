//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: invasive
/*
 * Unique C File Encryptor Example Program
 *
 * This program uses a simple XOR encryption method to encrypt a file.
 * The encryption key is a 16-byte string, and the file is encrypted in 16-byte chunks.
 *
 * Usage:
 *      ./file_encryptor <input_file> <output_file> <key>
 *
 * Example:
 *      ./file_encryptor input.txt output.txt 1234567890123456
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 16

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");

    if (!input_file || !output_file) {
        printf("Error opening files\n");
        return 1;
    }

    uint8_t key[16];
    uint8_t buffer[BUFFER_SIZE];

    if (strlen(argv[3]) != 16) {
        printf("Key must be 16 bytes long\n");
        return 1;
    }

    memcpy(key, argv[3], 16);

    while (fread(buffer, BUFFER_SIZE, 1, input_file) == 1) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] ^= key[i % 16];
        }
        fwrite(buffer, BUFFER_SIZE, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}