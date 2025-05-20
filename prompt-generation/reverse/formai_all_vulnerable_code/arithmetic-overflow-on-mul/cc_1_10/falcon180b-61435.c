//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_NAME_SIZE 256
#define MAGIC_NUMBER 0xDEADBEEF

typedef struct {
    char magic_number[4];
    int file_size;
    char file_name[MAX_FILE_NAME_SIZE];
} file_header_t;

void read_block(FILE *file, char *buffer, int block_number) {
    fseek(file, BLOCK_SIZE * block_number, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, file);
}

int compare_magic_number(char *magic_number, char *expected_magic_number) {
    if (strncmp(magic_number, expected_magic_number, 4) == 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    file_header_t file_header;
    char block_buffer[BLOCK_SIZE];
    int block_number;
    int file_size;
    char file_name[MAX_FILE_NAME_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(&file_header, sizeof(file_header_t), 1, file);
    if (compare_magic_number(file_header.magic_number, "DEAD")) {
        printf("Invalid magic number.\n");
        fclose(file);
        return 1;
    }

    fread(file_name, MAX_FILE_NAME_SIZE, 1, file);
    file_name[strcspn(file_name, "\0")] = '\0';

    printf("File name: %s\n", file_name);
    printf("File size: %d bytes\n", file_header.file_size);

    file_size = file_header.file_size;
    while (file_size > 0) {
        block_buffer[0] = 0;
        block_number = file_size / BLOCK_SIZE;
        if (file_size % BLOCK_SIZE!= 0) {
            block_buffer[0] = 1;
            block_number++;
        }

        read_block(file, block_buffer, block_number);
        fwrite(block_buffer, BLOCK_SIZE, 1, stdout);

        file_size -= BLOCK_SIZE;
    }

    fclose(file);
    return 0;
}