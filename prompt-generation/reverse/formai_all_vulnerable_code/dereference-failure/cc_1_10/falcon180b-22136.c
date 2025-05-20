//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64

void encrypt(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char key_buffer[KEY_LENGTH + 1] = {0};
    strncpy(key_buffer, key, KEY_LENGTH);

    char buffer[BLOCK_SIZE];
    size_t bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key_buffer[i % KEY_LENGTH];
        }

        bytes_written = fwrite(buffer, 1, bytes_read, output);

        if (bytes_read!= bytes_written) {
            printf("Error: could not write to output file.\n");
            exit(1);
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    encrypt(argv[1], argv[2], argv[3]);

    return 0;
}