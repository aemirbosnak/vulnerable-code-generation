#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    char data[0];
} Block;

Block* heap;
size_t heap_size, next_free;

void init(size_t initial_size) {
    heap_size = initial_size;
    heap = malloc(heap_size);
    next_free = 0;
}

void* alloc(size_t size) {
    if (next_free + size > heap_size)
        return NULL;
    Block* block = &heap[next_free];
    next_free += size;
    block->size = size;
    return block->data;
}

int main() {
    init(1024);
    int* p1 = (int*)alloc(sizeof(int) * 100);
    int* p2 = (int*)alloc(sizeof(int) * 200);
    int* p3 = (int*)alloc(sizeof(int) * 300);
    int* p4 = (int*)alloc(sizeof(int) * 400);
    int* p5 = (int*)alloc(sizeof(int) * 500); // integer overflow, exceeds initial heap size

    // Invalid access, accessing unallocated memory after heap overflow
    printf("%d\n", *((int*)heap));

    return 0;
}
