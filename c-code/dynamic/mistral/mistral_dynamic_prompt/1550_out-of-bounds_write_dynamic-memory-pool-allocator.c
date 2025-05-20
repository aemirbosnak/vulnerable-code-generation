#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define HEADER_SIZE 16

typedef struct Block {
    struct Block *next;
    char data[BLOCK_SIZE - HEADER_SIZE];
} Block;

Block *head = NULL;

Block* create_block() {
    Block *new_block = (Block*) malloc(BLOCK_SIZE);
    if (!new_block) return NULL;

    new_block->next = head;
    head = new_block;
    return new_block;
}

void* alloc(size_t size) {
    Block *current = head;

    while (current) {
        if (current->next == NULL) {
            create_block();
            current = head;
        }

        if (sizeof(current->data) >= size + HEADER_SIZE) {
            Block *temp = current;
            current = current->next;
            temp->next = NULL;
            return (void*)((char*)temp + HEADER_SIZE);
        }

        current = current->next;
    }

    return NULL;
}

void dealloc(void *ptr) {
    Block *current = head;

    while (current) {
        if (current->next == NULL) break;

        if (current->next == (Block*)((char*)ptr - HEADER_SIZE)) {
            current->next = current->next->next;
            return;
        }

        current = current->next;
    }
}

int main() {
    char* data = (char*)alloc(10);
    strcpy(data, "Vulnerable memory pool allocator");

    for (size_t i = 0; i < 20; i++) {
        data[(10 + i) * 3] = 'x';
    }

    dealloc(data);

    return 0;
}
