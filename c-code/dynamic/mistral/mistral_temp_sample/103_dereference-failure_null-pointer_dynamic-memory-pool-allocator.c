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

void allocate(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* get_memory(size_t size) {
    Block *current = head;
    while (current && current->size < size) {
        current = current->next;
    }

    if (!current) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }

    void *memory = (void *)(current + 1);
    return memory;
}

void free_memory(void *memory) {
    Block *current = head;
    Block *previous = NULL;

    while (current) {
        if (current == memory) {
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
    char *str = (char *)get_memory(20);
    strcpy(str, "Attacker's input");
    free_memory(str); // Dereference failure vulnerability
    return 0;
}
