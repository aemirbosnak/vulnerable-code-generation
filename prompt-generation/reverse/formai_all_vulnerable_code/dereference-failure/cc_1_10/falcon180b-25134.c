//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 1024
#define MAX_FILE_SIZE 1000000
#define MAGIC_NUMBER 0xdeadbeef

typedef struct {
    char magic_number[4];
    int file_size;
    char file_name[MAX_FILE_NAME_LEN];
} FILE_HEADER;

FILE_HEADER* recover_file_header(FILE* file) {
    FILE_HEADER* header = malloc(sizeof(FILE_HEADER));
    fseek(file, 0, SEEK_SET);
    fread(header->magic_number, 1, 4, file);
    if (memcmp(header->magic_number, "DEAD", 4)!= 0) {
        fprintf(stderr, "Invalid file magic number!\n");
        exit(1);
    }
    fseek(file, 4, SEEK_SET);
    fread(&header->file_size, 4, 1, file);
    fseek(file, 8, SEEK_SET);
    fread(header->file_name, 1, MAX_FILE_NAME_LEN, file);
    return header;
}

void recover_file(FILE* file, FILE_HEADER* header) {
    char* buffer = malloc(header->file_size);
    fseek(file, 0, SEEK_SET);
    fread(buffer, 1, header->file_size, file);
    fclose(file);
    FILE* output_file = fopen(header->file_name, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to create output file!\n");
        exit(1);
    }
    fwrite(buffer, 1, header->file_size, output_file);
    fclose(output_file);
    free(buffer);
}

int main() {
    FILE* file = fopen("recover.dat", "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open recover.dat!\n");
        exit(1);
    }
    FILE_HEADER* header = recover_file_header(file);
    recover_file(file, header);
    free(header);
    return 0;
}