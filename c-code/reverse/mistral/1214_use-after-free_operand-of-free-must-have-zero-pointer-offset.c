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

void my_malloc(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return;

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void my_free(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current && current != ptr) {
        prev = current;
        current = current->next;
    }

    if (!current) return;

    if (prev) prev->next = current->next;
    else head = current->next;

    free(current);
}

int main() {
    my_malloc(10);
    char *p = (char *)head + sizeof(Block);
    my_free(head);
    *p = 'A';
    printf("%c\n", *p);

    return 0;
}
