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

void* alloc(size_t size) {
    Block* block = (Block*)malloc(sizeof(Block) + size);
    block->size = size;
    return (char*)block + sizeof(Block);
}

void free_(void* ptr) {
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    free(block);
}

int main() {
    char* str = (char*)alloc(20);
    strcpy(str, "A secret message: 1337 is the key to my heart.");

    char* secret_message = (char*)alloc(100);
    strcpy(secret_message, str);

    free_(str);

    printf("The secret message: %s\n", secret_message);
    free_(secret_message);

    return 0;
}
