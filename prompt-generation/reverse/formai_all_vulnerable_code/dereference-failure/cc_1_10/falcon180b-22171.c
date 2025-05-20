//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BLOCK_SIZE 100
#define MAX_NUM_BLOCKS 100

typedef struct {
    int size;
    bool is_allocated;
    char *data;
} block_t;

block_t *blocks = NULL;
int num_blocks = 0;

void initialize_memory() {
    blocks = (block_t *)malloc(MAX_NUM_BLOCKS * sizeof(block_t));
    num_blocks = 0;
    for (int i = 0; i < MAX_NUM_BLOCKS; i++) {
        blocks[i].size = MAX_BLOCK_SIZE;
        blocks[i].is_allocated = false;
        blocks[i].data = (char *)malloc(MAX_BLOCK_SIZE);
    }
}

void *my_malloc(int size) {
    if (size <= 0) {
        printf("Error: Invalid size specified.\n");
        return NULL;
    }

    block_t *current_block = &blocks[0];
    while (current_block->size < size) {
        current_block++;
        if (current_block == &blocks[num_blocks - 1]) {
            printf("Error: Out of memory.\n");
            return NULL;
        }
    }

    if (current_block->is_allocated) {
        printf("Error: Memory already allocated.\n");
        return NULL;
    }

    current_block->is_allocated = true;
    void *result = current_block->data;
    return result;
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        printf("Error: Invalid pointer specified.\n");
        return;
    }

    block_t *current_block = &blocks[0];
    while (current_block->data!= ptr) {
        current_block++;
        if (current_block == &blocks[num_blocks - 1]) {
            printf("Error: Pointer not found.\n");
            return;
        }
    }

    current_block->is_allocated = false;
}

int main() {
    initialize_memory();

    void *ptr1 = my_malloc(50);
    void *ptr2 = my_malloc(100);
    void *ptr3 = my_malloc(150);

    printf("Allocated %d blocks of memory.\n", num_blocks);

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    printf("Freed %d blocks of memory.\n", num_blocks);

    return 0;
}