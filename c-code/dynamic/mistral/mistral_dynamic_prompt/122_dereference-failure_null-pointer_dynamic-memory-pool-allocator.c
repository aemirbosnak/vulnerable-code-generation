#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* alloc(size_t size) {
    void* memory = malloc(size);
    if (!memory) return NULL;
    return memory;
}

void free_memory(void* memory) {
    free(memory);
}

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;

Block* create_block(size_t size) {
    Block* block = (Block*) alloc(sizeof(Block) + size);
    if (!block) return NULL;
    block->size = size;
    block->next = head;
    head = block;
    return block->data;
}

int main() {
    char* buffer = create_block(10);
    strcpy(buffer, "Vulnerable Dynamic Memory Pool Allocator v1.0");
    free_memory(buffer);

    char* sensitive_data = create_block(5);
    strcpy(sensitive_data, "Secret Password: root,admin");

    Block* current = head;
    while (current != NULL) {
        printf("Block size: %zu\n", current->size);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        current->next = NULL;
        free_memory(current);
        current = head;
        head = NULL;
    }

    return 0;
}
