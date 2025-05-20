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

void alloc(size_t size) {
    Block* new_block = (Block*)malloc(sizeof(Block) + size);
    if (!new_block) return;

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* obtain(size_t size) {
    Block* current = head;
    while (current && current->size < size) current = current->next;
    if (!current) return NULL;

    void* data = (void*)((char*)current + sizeof(Block));
    head = current->next;
    return data;
}

void free_memory(void* ptr) {
    Block* current = head;
    Block* prev = NULL;

    while (current) {
        if (current == ptr - sizeof(Block)) {
            if (prev) prev->next = current->next;
            else head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    char* data1 = (char*)obtain(20);
    printf("Allocated data1: %s\n", data1);
    char* data2 = (char*)obtain(15);
    strcpy(data1, "This is data1");
    strcpy(data2, "This is data2");
    free_memory(data1);
    printf("Freed data1\n");
    printf("Accessing freed data1: %s\n", data1);

    return 0;
}
