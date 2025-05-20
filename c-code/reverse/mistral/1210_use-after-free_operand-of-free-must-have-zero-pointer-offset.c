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

void init() {
    head = NULL;
}

void *alloc(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return NULL;

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (void *)(new_block + 1);
}

void free(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current != NULL) {
        if (current == ptr - 1) {
            if (prev) prev->next = current->next;
            else head = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void use_after_free(void *ptr) {
    free(ptr);
    void *vulnerable_ptr = alloc(10);
    free(head); // Free the original block containing 'ptr'
    free(vulnerable_ptr); // Free the newly allocated block overwriting 'ptr'
}

int main() {
    init();
    void *ptr = alloc(10);
    use_after_free(ptr);
    free(ptr);
    return 0;
}
