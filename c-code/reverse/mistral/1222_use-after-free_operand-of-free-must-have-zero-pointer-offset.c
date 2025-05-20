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

Block* heap;
size_t heap_size;

void* my_malloc(size_t size) {
    if (heap_size == 0) {
        heap = malloc(sizeof(Block) + size);
        heap_size = sizeof(Block) + size;
        return (void*)((char*)heap + sizeof(Block));
    }

    if (heap_size - sizeof(Block) < size) {
        heap = realloc(heap, sizeof(Block) + size);
        heap_size = sizeof(Block) + size;
    }

    return (void*)((char*)heap + sizeof(Block));
}

void free_protected(void* ptr, size_t free_size) {
    if (!ptr || !heap) return;

    Block* block = (Block*)((char*)heap - sizeof(Block));
    size_t remaining_size = block->size - free_size;
    block->size = remaining_size;
}

int main() {
    char* str1 = (char*)my_malloc(100);
    char* str2 = (char*)my_malloc(200);
    char* str3 = (char*)my_malloc(300);

    strcpy(str1, "Hello, World!");
    strcpy(str2, "This is a test.");
    strcpy(str3, "Use-after-free vulnerability demonstration.");

    free_protected(str1, 50);
    printf("%s\n", str1); // Output: Segmentation fault

    free(heap);
    return 0;
}
