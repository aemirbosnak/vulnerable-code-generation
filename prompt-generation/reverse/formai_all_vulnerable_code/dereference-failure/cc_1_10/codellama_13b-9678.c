//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 10
#define MAX_BLOCK_SIZE 100

typedef struct {
    char *data;
    size_t size;
} block_t;

block_t blocks[MAX_BLOCKS];

void init_blocks() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].data = malloc(MAX_BLOCK_SIZE);
        blocks[i].size = 0;
    }
}

void free_blocks() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free(blocks[i].data);
    }
}

void print_blocks() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %s\n", i, blocks[i].data);
    }
}

void write_block(int index, char *data, size_t size) {
    if (index >= MAX_BLOCKS) {
        printf("Index out of range\n");
        return;
    }
    blocks[index].size = size;
    memcpy(blocks[index].data, data, size);
}

void read_block(int index, char *data, size_t size) {
    if (index >= MAX_BLOCKS) {
        printf("Index out of range\n");
        return;
    }
    memcpy(data, blocks[index].data, size);
}

int main() {
    init_blocks();
    char data[] = "Hello, World!";
    write_block(0, data, strlen(data));
    char read_data[MAX_BLOCK_SIZE];
    read_block(0, read_data, strlen(data));
    printf("Read data: %s\n", read_data);
    free_blocks();
    return 0;
}