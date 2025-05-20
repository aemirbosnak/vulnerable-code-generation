//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct block {
    int is_allocated;
    int size;
    char data[BLOCK_SIZE - sizeof(int) * 2];
} Block;

Block *free_list = (void*)0;

void init() {
    free_list = (Block*)malloc(BLOCK_SIZE);
    free_list->is_allocated = 0;
    free_list->size = BLOCK_SIZE - sizeof(int) * 2;
}

void *my_malloc(int size) {
    Block *current = free_list;
    while (current->size < size) {
        current = (Block*)((char*)current + current->size + sizeof(int));
    }

    if (current->size == size) {
        current->is_allocated = 1;
        return (void*)(current->data);
    } else {
        Block *new_block = (Block*)malloc(BLOCK_SIZE);
        new_block->is_allocated = 1;
        new_block->size = size;
        current->size -= size + sizeof(int);
        memcpy(new_block->data, (char*)current + current->size, size);
        return (void*)(new_block->data);
    }
}

void my_free(void *ptr) {
    if (ptr == NULL)
        return;

    char *data = (char*)ptr - sizeof(int);
    Block *current = (Block*)data;

    current->is_allocated = 0;

    Block *prev = free_list;
    while (prev!= NULL && prev->size < current->size) {
        prev = (Block*)((char*)prev + prev->size + sizeof(int));
    }

    if (prev!= NULL && prev->size == current->size) {
        prev->size += current->size + sizeof(int);
    }
}

int main() {
    init();

    void *ptr1 = my_malloc(10);
    void *ptr2 = my_malloc(20);
    void *ptr3 = my_malloc(30);

    printf("Allocated %d bytes at %p\n", 10, ptr1);
    printf("Allocated %d bytes at %p\n", 20, ptr2);
    printf("Allocated %d bytes at %p\n", 30, ptr3);

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    return 0;
}