#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

void* alloc_block(size_t size) {
    Block* block = (Block*) malloc(sizeof(Block) + size);
    if (!block) {
        perror("Error allocating memory");
        return NULL;
    }
    block->size = size;
    return (char*)(block + 1);
}

void free_block(void* ptr) {
    if (!ptr) {
        perror("Error freeing unallocated memory");
        return;
    }
    free((char*) ((Block*) ptr - 1));
}

int main() {
    void* data_pool = alloc_block(1024);
    if (!data_pool) {
        return 1;
    }

    char* message = "This is a test message.";
    memcpy(data_pool, message, strlen(message) + 1);

    // Deliberate bounds violation vulnerability
    printf("%s\n", (char*) data_pool + 1025);

    free_block(data_pool);
    return 0;
}
