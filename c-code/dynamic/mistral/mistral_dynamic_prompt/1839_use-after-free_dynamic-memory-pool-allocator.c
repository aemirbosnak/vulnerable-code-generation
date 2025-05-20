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

void alloc(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* get_memory(size_t size) {
    Block* current = head;
    size_t total_size = size + sizeof(Block);

    if (!head || total_size > current->size) {
        alloc(total_size);
        current = head;
    }

    void* memory = (void*)((char*)current + sizeof(Block));
    head = current->next;

    return memory;
}

void free_memory(void* memory) {
    if (!memory) return;

    Block* current = (Block*)((char*)memory - sizeof(Block));
    current->next = head;
    head = current;
}

int main() {
    alloc(10);
    char* str1 = (char*)get_memory(10);
    strcpy(str1, "Hello, World!");
    free_memory(str1);

    char* str2 = (char*)get_memory(10);
    strcpy(str2, "Goodbye, Cruel World!");

    // Use str1 after it has been freed, causing a use-after-free vulnerability
    printf("%s\n", str1);

    return 0;
}
