//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

struct block_header {
    int magic_number;
    int block_size;
    int next_block_index;
};

struct file_header {
    int magic_number;
    int num_blocks;
    int first_block_index;
};

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char *input_filename, *output_filename;
    struct file_header file_header;
    struct block_header block_header;
    char block_buffer[BLOCK_SIZE];
    int block_index, num_blocks;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_filename = argv[1];
    output_filename = argv[2];

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    fread(&file_header, sizeof(struct file_header), 1, input_file);
    if (file_header.magic_number!= 0x12345678) {
        printf("Error: Input file is not a valid data recovery file.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    num_blocks = file_header.num_blocks;
    block_index = file_header.first_block_index;

    while (block_index!= -1) {
        fseek(input_file, block_index * BLOCK_SIZE, SEEK_SET);
        fread(&block_header, sizeof(struct block_header), 1, input_file);

        if (block_header.magic_number!= 0x87654321) {
            printf("Error: Input file is corrupted.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        if (block_header.block_size!= BLOCK_SIZE) {
            printf("Error: Input file is corrupted.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        fread(block_buffer, BLOCK_SIZE, 1, input_file);
        fwrite(block_buffer, BLOCK_SIZE, 1, output_file);

        block_index = block_header.next_block_index;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery completed successfully!\n");

    return 0;
}