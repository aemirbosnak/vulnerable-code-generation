#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

void add_block(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return;

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void *get_block(size_t size) {
    Block *current = head;

    while (current != NULL) {
        if (current->size >= size) {
            void *data = (void *)&current->data[current->size];
            current->size -= size;
            return data;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    add_block(10);
    char* vulnerable_data = (char*)get_block(1);

    // Out-of-bounds write vulnerability here:
    vulnerable_data[0] = 'A';
    vulnerable_data[1] = 'B'; // Writes beyond the allocated block

    printf("vulnerable_data: %s\n", vulnerable_data);

    return 0;
}
