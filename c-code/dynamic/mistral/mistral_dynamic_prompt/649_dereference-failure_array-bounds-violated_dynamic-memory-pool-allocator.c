#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

void alloc(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        perror("Out of memory");
        return;
    }
    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void *get_memory(size_t size) {
    if (size == 0) {
        perror("Invalid size");
        return NULL;
    }
    Block *current = head;
    while (current) {
        if (current->size >= size) {
            void *mem_ptr = (void *)(current + 1);
            current->size -= size;
            return mem_ptr;
        }
        current = current->next;
    }
    alloc(size);
    return get_memory(size);
}

int main() {
    alloc(10);
    alloc(5);
    int *buffer = (int *)get_memory(sizeof(int) * 10);

    for (size_t i = 0; i < 11; ++i) {
        buffer[i] = i;
        printf("buffer[%zu] = %d\n", i, buffer[i]);
    }

    // Vulnerability: Accessing buffer[11] which is out of bounds
    printf("buffer[11] = %d\n", buffer[11]);

    // Free memory
    free((char *)buffer - sizeof(Block));

    return 0;
}
