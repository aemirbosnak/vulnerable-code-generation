//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

typedef struct {
    int block_size;
    int num_blocks;
    char *filename;
    FILE *fp;
} FileHeader;

typedef struct {
    int size;
    char data[BLOCK_SIZE];
} Block;

void read_file_header(FILE *fp, FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(FileHeader), 1, fp);
}

void write_file_header(FILE *fp, FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(FileHeader), 1, fp);
}

void read_block(FILE *fp, int block_num, Block *block) {
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    fread(block, sizeof(Block), 1, fp);
}

void write_block(FILE *fp, int block_num, Block *block) {
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    fwrite(block, sizeof(Block), 1, fp);
}

void print_file_header(FileHeader *header) {
    printf("File Header:\n");
    printf("Block Size: %d\n", header->block_size);
    printf("Number of Blocks: %d\n", header->num_blocks);
    printf("Filename: %s\n", header->filename);
}

void print_block(Block *block) {
    printf("Block %d:\n", block->size);
    printf("Data:\n");
    for (int i = 0; i < block->size; i++) {
        printf("%c", block->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    FileHeader header;
    Block block;

    // Open file for reading
    fp = fopen("example.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file header
    read_file_header(fp, &header);
    print_file_header(&header);

    // Read first block
    read_block(fp, 0, &block);
    printf("Block 0:\n");
    print_block(&block);

    // Read last block
    int last_block = header.num_blocks - 1;
    read_block(fp, last_block, &block);
    printf("Block %d:\n", last_block);
    print_block(&block);

    // Close file
    fclose(fp);

    return 0;
}