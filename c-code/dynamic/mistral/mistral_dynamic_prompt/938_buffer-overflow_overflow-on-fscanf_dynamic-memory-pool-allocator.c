#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemBlock {
    void *start;
    size_t size;
    struct MemBlock *next;
} MemBlock;

MemBlock *mem_pool = NULL;

void *allocate(size_t size) {
    MemBlock *new_block = malloc(sizeof(MemBlock) + size);
    if (!new_block) return NULL;

    new_block->start = ((char *)new_block + sizeof(MemBlock));
    new_block->size = size;
    new_block->next = mem_pool;
    mem_pool = new_block;
    return new_block->start;
}

void free_mem(void *ptr) {
    MemBlock *current = mem_pool, *prev = NULL;
    while (current != NULL) {
        if (current->start == ptr) {
            if (prev == NULL) mem_pool = current->next;
            else prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main(int argc, char **argv) {
    char buffer[16];
    if (argc < 2) return 0;

    void *p = allocate(atoi(argv[1]) * 20);
    fscanf(stdin, "%s", buffer);
    strcpy((char *)p, buffer);
    free_mem(p);
    return 0;
}
