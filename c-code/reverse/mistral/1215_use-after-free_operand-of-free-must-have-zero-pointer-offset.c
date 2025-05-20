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

Block* my_malloc(size_t size) {
    Block* block = (Block*)malloc(sizeof(Block) + size);
    if (!block) return NULL;
    block->size = size;
    return block;
}

void my_free(Block* block) {
    free(block);
}

void* my_realloc(void* ptr, size_t new_size) {
    Block* old_block = (Block*)ptr;
    Block* new_block = my_malloc(new_size);

    if (!new_block) return NULL;

    if (old_block && new_size > old_block->size) {
        memcpy(new_block, old_block, old_block->size);
    }

    free(old_block);
    return new_block;
}

int main() {
    Block* block1 = my_malloc(10);
    char* str1 = (char*)block1 + sizeof(Block);
    strcpy(str1, "Hello, World!");

    Block* block2 = my_realloc(block1, 20);
    char* str2 = (char*)block2 + sizeof(Block);
    strcpy(str2 + 10, "This is a new string.");

    my_free(block1); // Use-after-free vulnerability here

    printf("%s\n", str1); // Output: "Hello, World!"
    printf("%s\n", str2); // Output: "This is a new string."

    return 0;
}
