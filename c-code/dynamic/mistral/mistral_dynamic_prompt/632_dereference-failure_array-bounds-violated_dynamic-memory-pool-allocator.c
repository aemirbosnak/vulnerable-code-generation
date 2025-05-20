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

void* alloc(size_t size) {
    Block* block = malloc(sizeof(Block) + size);
    if (!block) return NULL;
    block->size = size;
    return (char*)(block + 1);
}

void free_(void* ptr) {
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    free(block);
}

int main() {
    void* buffer = alloc(10);
    char* str = "A secure program should never access uninitialized memory";
    memcpy(buffer, str, strlen(str) + 1);

    char* vulnerable_ptr = (char*)buffer + sizeof(Block) + 10;
    printf("%c\n", *vulnerable_ptr); // Dereference failure (out-of-bounds access)

    free_(buffer);
    return 0;
}
