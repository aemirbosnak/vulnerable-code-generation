#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    void* data;
    size_t size;
    struct Block* next;
} Block;

Block* head = NULL;

void* malloc_safe(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) return NULL;
    new_block->data = ((char*)new_block) + sizeof(Block);
    new_block->size = size;
    new_block->next = head;
    head = new_block;
    return new_block->data;
}

void free_memory(void* ptr) {
    Block* current = head;
    Block* previous = NULL;

    while (current) {
        if (current->data == ptr) {
            if (previous)
                previous->next = current->next;
            else
                head = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void dump_memory() {
    Block* current = head;
    printf("Memory Pool:\n");
    while (current) {
        printf("Address: %p, Size: %zu, Data: %p\n", current, current->size, current->data);
        current = current->next;
    }
}

int main() {
    char* buffer = (char*)malloc_safe(1024);
    printf("Buffer address: %p\n", buffer);

    if (sscanf(getenv("PATH"), "%s%n", buffer, (size_t*)&buffer[1023]) > 1)
        printf("Buffer overflow!\n");

    dump_memory();

    free_memory(buffer);
    dump_memory();

    return 0;
}
