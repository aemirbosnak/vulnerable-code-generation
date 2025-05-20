#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 100
#define BLOCK_SIZE 50

typedef struct Block {
    void *data;
    size_t size;
    struct Block *next;
} Block;

Block pool[POOL_SIZE];
Block *free_list = NULL;

void init() {
    int i;
    for (i = 0; i < POOL_SIZE; ++i) {
        pool[i].data = malloc(BLOCK_SIZE);
        pool[i].size = BLOCK_SIZE;
        pool[i].next = free_list;
        free_list = &pool[i];
    }
}

Block *alloc(size_t size) {
    Block *current = free_list;
    while (current != NULL) {
        if (current->size >= size) {
            void *data = current->data;
            free_list = current->next;
            current->data = NULL;
            current->size = size;
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    init();
    Block *block = alloc(100);
    if (block != NULL) {
        char *str = (char *) block->data;
        memset(str, 'A', 100);
        printf("Filled block:\n%s\n", str);
        free(block);
    } else {
        printf("No suitable block found.\n");
    }

    // Intentional dereference error
    printf("%c\n", *(char *) free_list);

    return 0;
}
