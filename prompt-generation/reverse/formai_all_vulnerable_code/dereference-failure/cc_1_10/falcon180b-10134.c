//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BLOCKS 10
#define BLOCK_SIZE 4096

typedef struct {
    char data[BLOCK_SIZE];
    int is_allocated;
} block_t;

block_t blocks[NUM_BLOCKS];

int alloc_block(int block_num) {
    if (blocks[block_num].is_allocated) {
        return -1;
    }
    blocks[block_num].is_allocated = 1;
    return 0;
}

int free_block(int block_num) {
    if (!blocks[block_num].is_allocated) {
        return -1;
    }
    blocks[block_num].is_allocated = 0;
    return 0;
}

int read_block(int block_num, void* buf) {
    if (!blocks[block_num].is_allocated) {
        return -1;
    }
    memcpy(buf, blocks[block_num].data, BLOCK_SIZE);
    return 0;
}

int write_block(int block_num, const void* buf) {
    if (!blocks[block_num].is_allocated) {
        return -1;
    }
    memcpy(blocks[block_num].data, buf, BLOCK_SIZE);
    return 0;
}

int main() {
    int i;

    // Initialize all blocks as free
    for (i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].is_allocated = 0;
        memset(blocks[i].data, 0, BLOCK_SIZE);
    }

    // Allocate and write to block 0
    if (alloc_block(0) == 0) {
        if (write_block(0, "Hello, world!") == 0) {
            printf("Block 0 allocated and written successfully.\n");
        }
    }

    // Free block 0
    if (free_block(0) == 0) {
        printf("Block 0 freed successfully.\n");
    }

    // Allocate and write to block 1
    if (alloc_block(1) == 0) {
        if (write_block(1, "This is block 1.") == 0) {
            printf("Block 1 allocated and written successfully.\n");
        }
    }

    // Read from block 1
    void* buf = malloc(BLOCK_SIZE);
    if (read_block(1, buf) == 0) {
        printf("Block 1 read successfully:\n%s\n", buf);
        free(buf);
    }

    // Free block 1
    if (free_block(1) == 0) {
        printf("Block 1 freed successfully.\n");
    }

    return 0;
}