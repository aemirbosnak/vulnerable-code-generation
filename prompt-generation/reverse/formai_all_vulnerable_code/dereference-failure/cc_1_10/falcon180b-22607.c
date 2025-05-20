//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Function to read input file
void read_input_file(FILE *input_file, char *buffer, int *buffer_index, int *file_size) {
    int bytes_read;

    while ((bytes_read = fread(buffer + *buffer_index, 1, BUFFER_SIZE - *buffer_index, input_file)) > 0) {
        *buffer_index += bytes_read;
        *file_size += bytes_read;
    }
}

// Function to write output file
void write_output_file(FILE *output_file, char *buffer, int buffer_index, int file_size) {
    int bytes_written;

    while (buffer_index < file_size) {
        bytes_written = fwrite(buffer + buffer_index, 1, BUFFER_SIZE - buffer_index, output_file);
        if (bytes_written == 0) {
            printf("Error writing output file.\n");
            exit(1);
        }
        buffer_index += bytes_written;
    }
}

// Function to compress input file
void compress_input_file(FILE *input_file, FILE *output_file) {
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;
    int file_size = 0;

    read_input_file(input_file, buffer, &buffer_index, &file_size);

    int i, j;
    for (i = 0, j = 0; i < file_size; i++) {
        if (i == 0 || buffer[i]!= buffer[i - 1]) {
            buffer[j++] = buffer[i];
        }
    }

    write_output_file(output_file, buffer, j, file_size);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    compress_input_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}