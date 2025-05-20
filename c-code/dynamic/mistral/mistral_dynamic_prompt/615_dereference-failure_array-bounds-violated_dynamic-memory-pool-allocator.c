#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;

void allocate(size_t size) {
    Block* newBlock = (Block*) malloc(sizeof(Block) + size);
    if (!newBlock) {
        fprintf(stderr, "Out of memory!\n");
        return;
    }

    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
}

void* get_memory(size_t size) {
    Block* current = head;

    while (current && current->size < size) {
        current = current->next;
    }

    if (!current) {
        fprintf(stderr, "Not enough memory available!\n");
        return NULL;
    }

    void* mem = (void*) ((char*) current + sizeof(Block) + current->size);
    return mem;
}

void free_memory(void* ptr) {
    Block* current = head;
    Block* previous = NULL;

    while (current) {
        if (current && ((char*) current + sizeof(Block) <= ptr && (char*) current->next > ptr)) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }

            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    allocate(10);
    allocate(50);
    allocate(100);

    char* buffer = (char*) get_memory(100);

    printf("Allocated buffer address: %p\n", buffer);

    // Dereference failure vulnerability here
    printf("%c\n", *(buffer + 101));

    free_memory(buffer);

    return 0;
}
