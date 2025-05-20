//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define BLOCK_SIZE 4096

typedef struct {
    char filename[12];
    char extension[4];
    unsigned int size;
    unsigned char data[MAX_FILE_SIZE];
} file_header_t;

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char input_filename[20], output_filename[20];
    unsigned char buffer[BLOCK_SIZE];
    file_header_t header;
    int i, j, num_blocks;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    strcat(input_filename, ".raw");

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    fread(&header, sizeof(file_header_t), 1, input_file);
    if (header.size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit.\n");
        fclose(input_file);
        return 1;
    }

    strcpy(output_filename, argv[1]);
    strcat(output_filename, ".recovered");

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Output file creation failed.\n");
        fclose(input_file);
        return 1;
    }

    num_blocks = (header.size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (i = 0; i < num_blocks; i++) {
        fseek(input_file, i * BLOCK_SIZE, SEEK_SET);
        fread(buffer, BLOCK_SIZE, 1, input_file);
        for (j = 0; j < BLOCK_SIZE; j++) {
            if (buffer[j] == 0xff) {
                buffer[j] = 0x00;
            }
        }
        fwrite(buffer, BLOCK_SIZE, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File recovery completed successfully.\n");
    return 0;
}