//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct {
    char filename[100];
    int size;
    int num_blocks;
    int block_list[MAX_FILE_SIZE / BLOCK_SIZE];
} FileHeader;

void read_file_header(FILE *fp, FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(FileHeader), 1, fp);
}

void write_file_header(FILE *fp, FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(FileHeader), 1, fp);
}

int is_block_allocated(FileHeader *header, int block_num) {
    for (int i = 0; i < header->num_blocks; i++) {
        if (header->block_list[i] == block_num) {
            return 1;
        }
    }
    return 0;
}

int get_free_block(FileHeader *header) {
    for (int i = 0; i < MAX_FILE_SIZE / BLOCK_SIZE; i++) {
        if (!is_block_allocated(header, i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    FileHeader header;
    read_file_header(fp, &header);

    int num_blocks = (header.size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    if (num_blocks > MAX_FILE_SIZE / BLOCK_SIZE) {
        printf("File is too large\n");
        return 1;
    }

    int i, j;
    for (i = 0; i < num_blocks; i++) {
        if (!is_block_allocated(&header, i)) {
            printf("Block %d is not allocated\n", i);
            fseek(fp, i * BLOCK_SIZE, SEEK_SET);
            fwrite("\0", 1, BLOCK_SIZE, fp);
        }
    }

    fclose(fp);
    printf("Data recovery complete\n");
    return 0;
}