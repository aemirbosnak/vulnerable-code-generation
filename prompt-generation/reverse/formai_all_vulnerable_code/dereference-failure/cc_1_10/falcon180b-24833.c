//Falcon-180B DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the size of the memory block
#define MEMORY_BLOCK_SIZE 1024

// Define the structure of a memory block
typedef struct {
    size_t size;
    int free;
    struct memory_block *next;
} memory_block_t;

// Initialize the memory pool
void init_memory_pool(void) {
    memory_block_t *head = (memory_block_t *) malloc(sizeof(memory_block_t));
    if (head == NULL) {
        printf("Error: unable to allocate memory for head\n");
        exit(1);
    }
    head->size = MEMORY_BLOCK_SIZE - sizeof(memory_block_t);
    head->free = 1;
    head->next = NULL;
}

// Allocate a memory block of the specified size
void *allocate_memory(size_t size) {
    memory_block_t *cur = (memory_block_t *) malloc(sizeof(memory_block_t));
    if (cur == NULL) {
        printf("Error: unable to allocate memory for block\n");
        exit(1);
    }
    cur->size = size;
    cur->free = 0;
    cur->next = NULL;
    return (void *) (cur + 1);
}

// Free a memory block
void free_memory(void *ptr) {
    memory_block_t *cur = (memory_block_t *) (((char *) ptr) - sizeof(memory_block_t));
    cur->free = 1;
}

// Print the status of the memory pool
void print_memory_status(void) {
    memory_block_t *head = (memory_block_t *) malloc(sizeof(memory_block_t));
    memory_block_t *cur = head;
    while (cur!= NULL) {
        printf("Block size: %zu, Free: %d\n", cur->size, cur->free);
        cur = cur->next;
    }
}

int main() {
    init_memory_pool();
    void *ptr1 = allocate_memory(64);
    void *ptr2 = allocate_memory(128);
    void *ptr3 = allocate_memory(256);
    printf("Allocated 3 blocks of memory\n");
    print_memory_status();
    free_memory(ptr1);
    printf("Freed first block of memory\n");
    print_memory_status();
    free_memory(ptr2);
    printf("Freed second block of memory\n");
    print_memory_status();
    free_memory(ptr3);
    printf("Freed third block of memory\n");
    print_memory_status();
    return 0;
}