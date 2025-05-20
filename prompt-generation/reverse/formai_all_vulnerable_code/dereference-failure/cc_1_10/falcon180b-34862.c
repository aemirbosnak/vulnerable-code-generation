//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define MAGIC_NUM "DATA"

typedef struct {
    char magic[4];
    int file_size;
    char data[MAX_FILE_SIZE];
} file_header;

void write_file(char *filename, file_header *header) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fwrite(header, sizeof(file_header), 1, fp);
    fclose(fp);
}

file_header *read_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    file_header *header = (file_header *) malloc(sizeof(file_header));
    fread(header, sizeof(file_header), 1, fp);
    fclose(fp);
    return header;
}

int main() {
    char *filename = "data.dat";
    file_header *header = read_file(filename);
    if (strncmp(header->magic, MAGIC_NUM, 4)!= 0) {
        printf("Error: Invalid file format\n");
        exit(1);
    }
    printf("File size: %d bytes\n", header->file_size);
    printf("Data:\n");
    for (int i = 0; i < header->file_size; i++) {
        printf("%c", header->data[i]);
    }
    printf("\n");
    return 0;
}