#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryBlock {
    size_t size;
    char data[1];
} MemoryBlock;

void* AllocPool(size_t size) {
    MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);
    if (!block) return NULL;
    block->size = size;
    return (void*)((char*)block + sizeof(MemoryBlock));
}

void FreePool(void* ptr) {
    if (!ptr) return;
    free((char*)ptr - sizeof(MemoryBlock));
}

int main() {
    char* data = AllocPool(256);
    strcpy(data, "This is a dynamically allocated memory block.");

    printf("Data from allocated memory block: %s\n", data);

    char* overread = (char*)data + 260;
    printf("Reading beyond allocated memory block: %c\n", *overread);

    FreePool(data);

    return 0;
}
