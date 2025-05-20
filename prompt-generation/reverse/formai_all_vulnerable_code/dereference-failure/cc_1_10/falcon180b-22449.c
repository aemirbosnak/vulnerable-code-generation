//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a block
typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

// Initialize the heap
void init() {
    Block *heap = (Block *)malloc(sizeof(Block));
    heap->size = 0;
    heap->free = 1;
    heap->next = NULL;
}

// Allocate a block of memory
void *my_malloc(size_t size) {
    Block *current = (Block *)malloc(sizeof(Block));
    current->size = size;
    current->free = 0;
    current->next = NULL;

    Block *prev = NULL;
    Block *next = (Block *)malloc(sizeof(Block));

    while (next->size < size && next!= NULL) {
        prev = next;
        next = next->next;
    }

    if (next == NULL) {
        current->next = NULL;
    } else {
        current->next = next;
        prev->next = current;
    }

    return (void *)((char *)current + sizeof(Block));
}

// Free a block of memory
void my_free(void *ptr) {
    if (ptr == NULL)
        return;

    char *block = (char *)ptr - sizeof(Block);
    Block *current = (Block *)block;

    current->free = 1;
}

int main() {
    init();

    void *p1 = my_malloc(10);
    void *p2 = my_malloc(20);
    void *p3 = my_malloc(30);

    printf("Allocated %d bytes at %p\n", 10, p1);
    printf("Allocated %d bytes at %p\n", 20, p2);
    printf("Allocated %d bytes at %p\n", 30, p3);

    my_free(p1);
    my_free(p3);

    printf("Freed %d bytes at %p\n", 10, p1);
    printf("Freed %d bytes at %p\n", 30, p3);

    return 0;
}