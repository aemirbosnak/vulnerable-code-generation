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

Block *heap = NULL;

void *my_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }

    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        return NULL;
    }

    new_block->size = size;
    new_block->next = heap;
    heap = new_block;

    return (void *)((char *)new_block + sizeof(Block));
}

void my_free(void *ptr) {
    Block *current = heap;
    Block *previous = NULL;

    while (current != NULL) {
        if (current == ptr) {
            if (previous) {
                previous->next = current->next;
            } else {
                heap = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    void *p1 = my_malloc(10);
    void *p2 = my_malloc(20);
    void *p3 = my_malloc(30);

    my_free(p1);
    int *arr = (int *)p2;
    arr[0] = 42;
    printf("arr[0] = %d\n", arr[0]);

    return 0;
}
