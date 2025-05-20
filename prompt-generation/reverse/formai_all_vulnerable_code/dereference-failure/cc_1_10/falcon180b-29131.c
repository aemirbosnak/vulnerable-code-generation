//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1000000 // Maximum amount of memory to allocate

// Structure for memory block
typedef struct {
    size_t size;
    void *ptr;
    struct memory_block *next;
} memory_block;

// Linked list for free memory blocks
memory_block *free_list = NULL;

// Function to initialize memory management system
void init_memory_management() {
    free_list = (memory_block *)malloc(sizeof(memory_block));
    free_list->size = MAX_MEMORY - sizeof(memory_block);
    free_list->ptr = (void *)((int)free_list + sizeof(memory_block));
    free_list->next = NULL;
}

// Function to allocate memory
void *my_malloc(size_t num_bytes) {
    memory_block *current = free_list;
    while (current!= NULL && current->size < num_bytes) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }

    void *result = (void *)((int)current->ptr + sizeof(memory_block));
    current->size -= num_bytes;
    current->ptr = (void *)((int)current->ptr + num_bytes);

    return result;
}

// Function to free memory
void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    memory_block *current = free_list;
    while (current!= NULL && current->ptr!= ptr) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid pointer!\n");
        exit(1);
    }

    free_list = current->next;
    free(current);
}

int main() {
    init_memory_management();

    void *ptr1 = my_malloc(100);
    void *ptr2 = my_malloc(200);
    void *ptr3 = my_malloc(300);

    printf("Allocated %d bytes at %p\n", 100, ptr1);
    printf("Allocated %d bytes at %p\n", 200, ptr2);
    printf("Allocated %d bytes at %p\n", 300, ptr3);

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    return 0;
}