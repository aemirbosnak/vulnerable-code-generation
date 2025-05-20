#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data;
} Block;

Block *pool[POOL_SIZE];
int pool_index = 0;

void *allocate() {
    if (pool_index >= POOL_SIZE) return NULL;
    pool[pool_index] = malloc(sizeof(Block));
    if (!pool[pool_index]) return NULL;
    pool[pool_index]->data = rand();
    return pool[pool_index];
}

void deallocate(void *ptr) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (pool[i] == ptr) {
            free(ptr);
            pool[i] = NULL;
            return;
        }
    }
}

int main() {
    srand(time(NULL));

    void *block1 = allocate();
    printf("Allocated block1: %p, Data: %d\n", block1, ((Block *)block1)->data);

    void *block2 = allocate();
    printf("Allocated block2: %p, Data: %d\n", block2, ((Block *)block2)->data);

    deallocate(block1);
    printf("Deallocated block1: %p\n", block1);

    // Use after free vulnerability
    printf("Data from freed block1: %d\n", ((Block *)block1)->data);

    return 0;
}
