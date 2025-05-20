#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

void* allocate(size_t size) {
    Block* block = (Block*) malloc(sizeof(Block) + size);
    if (!block) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    block->size = size;
    return (char*) block + sizeof(Block);
}

void deallocate(void* ptr) {
    if (!ptr) return;
    free((Block*) ((char*) ptr - sizeof(Block)));
}

int main() {
    char* buffer = (char*) allocate(42);
    strcpy(buffer, "This is a vulnerable buffer");
    printf("Buffer: %s\n", buffer);
    int* number = (int*) buffer + 22;
    *number = 42;
    printf("22th byte as int: %d\n", *number);
    deallocate(buffer);
    return 0;
}
