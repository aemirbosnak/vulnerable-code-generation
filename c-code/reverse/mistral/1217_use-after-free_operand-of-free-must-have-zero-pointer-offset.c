#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

Block* custom_malloc(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return NULL;

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (char *)new_block + sizeof(Block);
}

void custom_free(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current && current < (Block *)ptr) {
        prev = current;
        current = current->next;
    }

    if (current && current == head) {
        head = current->next;
    } else if (prev) {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    char *a = (char *)custom_malloc(10);
    char *b = (char *)custom_malloc(20);
    char *c = (char *)custom_malloc(30);

    custom_free(a);
    custom_free(b);

    char *d = (char *)custom_malloc(40);

    // Use-after-free vulnerability occurs here
    printf("%c\n", *a);

    return 0;
}
