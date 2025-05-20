#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int id;
    char name[32];
} PoolBlock;

PoolBlock *pool = NULL;
int pool_index = 0;

void init_pool() {
    pool = malloc(POOL_SIZE * sizeof(PoolBlock));
    if (pool == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

void free_pool() {
    free(pool);
}

void add_block(int id, const char *name) {
    if (pool_index >= POOL_SIZE) {
        fprintf(stderr, "Memory pool is full\n");
        return;
    }
    PoolBlock *block = &pool[pool_index++];
    block->id = id;
    // Deliberate buffer overflow vulnerability
    sscanf(name, "%s", block->name);
}

void print_blocks() {
    for (int i = 0; i < pool_index; i++) {
        printf("ID: %d, Name: %s\n", pool[i].id, pool[i].name);
    }
}

int main() {
    init_pool();
    add_block(1, "ShortName");
    // Trigger buffer overflow by providing an excessively long string
    add_block(2, "ThisIsAVeryLongStringThatWillCauseABufferOverflowBecauseTheNameFieldOnlyHas32CharactersAndWeAreExceedingItWithAnExtraCharacterWhichIsNotHandledProperlyInOurAllocatorWhichUsesSScanfToParseStringsFromUserInput");
    print_blocks();
    free_pool();
    return 0;
}
