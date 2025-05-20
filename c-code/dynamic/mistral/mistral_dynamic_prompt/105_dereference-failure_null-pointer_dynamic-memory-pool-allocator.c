#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PoolBlock {
    size_t size;
    struct PoolBlock* next;
    char data[1];
} PoolBlock;

PoolBlock* head = NULL;

PoolBlock* alloc(size_t size) {
    PoolBlock* newBlock = (PoolBlock*)calloc(1, size + sizeof(PoolBlock));
    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
    return newBlock + 1;
}

void free_(void* ptr) {
    PoolBlock* block = (PoolBlock*)(ptr - 1);
    block->next = head;
    head = block;
}

void* realloc_(void* ptr, size_t newSize) {
    PoolBlock* block = (PoolBlock*)(ptr - 1);
    block->size = newSize;
    return alloc(newSize);
}

int main() {
    char* userInput = alloc(10);
    printf("Enter a string (10 characters max): ");
    fgets(userInput, 11, stdin); // Allowing 1 extra char for the null terminator

    int len = strlen(userInput);
    userInput = realloc_(userInput, len + 1); // Vulnerability: realloc_ does not check if the newSize > len + 1

    printf("You entered: %s\n", userInput);

    free_(userInput);

    return 0;
}
