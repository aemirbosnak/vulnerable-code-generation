#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char *data;
    struct Block *next;
} Block;

Block *pool = NULL;
size_t pool_size = 0;

void allocate(size_t size) {
    if (pool_size <= 0 || pool[pool_size - 1].size < size) {
        pool = realloc(pool, (pool_size + 1 + sizeof(Block)) * sizeof(char));
        pool[pool_size].size = size;
        pool[pool_size].next = pool;
        pool_size++;
    }
    pool[pool_size - 1].data = (char *)malloc(size);
}

void deallocate(size_t index) {
    if (index >= pool_size || index < 0) {
        printf("Invalid index\n");
        return;
    }
    free(pool[index].data);
    memset(&pool[index], 0, sizeof(Block));
}

int main() {
    char buf[10];
    allocate(256);
    printf("Enter some input:\n");
    gets(buf);

    // Execute arbitrary code from the input
    system(buf);

    return 0;
}
