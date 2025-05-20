#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POISON 0xDEADBEEF

typedef struct {
    size_t size;
    int poison;
} Block;

void* my_malloc(size_t size) {
    Block *block = (Block*)malloc(sizeof(Block) + size);
    if (!block) return NULL;
    block->size = size;
    block->poison = POISON;
    return (char*)block + sizeof(Block);
}

void my_free(void *ptr) {
    if (!ptr) return;
    Block *block = (Block*)((char*)ptr - sizeof(Block));
    if (block->poison != POISON) {
        fprintf(stderr, "Double free detected!\n");
        exit(1);
    }
    block->poison = 0;
    free(block);
}

int main() {
    int *a = (int*)my_malloc(sizeof(int));
    *a = 42;
    printf("Value: %d\n", *a);

    my_free(a);

    // Vulnerability: Accessing freed memory
    if (*a == 42) {
        printf("Accessed freed memory successfully!\n");
    } else {
        printf("Failed to access freed memory.\n");
    }

    return 0;
}
