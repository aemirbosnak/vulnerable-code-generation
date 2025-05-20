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

void allocate(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* get_memory(size_t size) {
    Block* current = head;
    while (current != NULL) {
        if (current->size >= size) {
            void* memory = (void*) ((char*) current + sizeof(Block));
            Block* to_remove = current;
            current = current->next;
            free(to_remove);
            return memory;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    allocate(100);
    allocate(200);
    allocate(300);

    int* data1 = (int*) get_memory(sizeof(int) * 100);
    int* data2 = (int*) get_memory(sizeof(int) * 200);
    int* data3 = (int*) get_memory(sizeof(int) * 300);

    free(data1); // Forget to free memory

    // Continue with the program...

    return 0;
}
