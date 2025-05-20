#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block;

block *free_list = NULL;

void *custom_malloc(size_t size) {
    if (size == 0) return NULL;
    block *current = free_list;
    while (current != NULL) {
        if (current->free && current->size >= size) {
            current->free = 0;
            return (char *)current + sizeof(block);
        }
        current = current->next;
    }
    block *new_block = sbrk(BLOCK_SIZE);
    new_block->size = BLOCK_SIZE - sizeof(block);
    new_block->free = 0;
    new_block->next = NULL;
    return (char *)new_block + sizeof(block);
}

void custom_free(void *ptr) {
    if (ptr == NULL) return;
    block *to_free = (block *)((char *)ptr - sizeof(block));
    to_free->free = 1;
}

int main() {
    void *p1 = custom_malloc(500);
    void *p2 = custom_malloc(300);
    custom_free(p1);
    p1 = custom_malloc(600); // This should fail due to insufficient space in the first block
    printf("Allocation after free: %s\n", p1 ? "Success" : "Failure");
    return 0;
}
