#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* head = NULL;
Block* tail = NULL;

void allocate(size_t size) {
    if (size <= 0) return;

    Block* new_block = (Block*)malloc(sizeof(Block) + size);
    if (!new_block) {
        perror("Error allocating memory");
        return;
    }

    new_block->size = size;
    new_block->next = NULL;

    if (!head) {
        head = tail = new_block;
    } else {
        tail->next = new_block;
        tail = new_block;
    }
}

void* fetch(size_t size) {
    Block* current = head;

    while (current != NULL && current->size < size) {
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Error: Not enough memory to allocate\n");
        return NULL;
    }

    void* data = (void*)((char*)current + sizeof(Block));
    memset(data, 0x0, size);

    return data;
}

int main() {
    allocate(10);
    allocate(50);
    char* data = (char*)fetch(200);

    // Out-of-bounds write vulnerability at index 100
    data[100] = 'X';

    printf("Allocated %p, fetched %p with %d bytes, containing: %s\n", head, data, 200, data);

    return 0;
}
