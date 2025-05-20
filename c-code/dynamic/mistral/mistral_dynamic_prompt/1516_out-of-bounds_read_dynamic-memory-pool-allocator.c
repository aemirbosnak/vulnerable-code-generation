#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    void* data;
    size_t size;
    struct Block* next;
} Block;

Block* heap = NULL;

void allocate(size_t size) {
    Block* newBlock = (Block*) malloc(sizeof(Block) + size);
    if (!newBlock) {
        printf("Error: Out of memory\n");
        return;
    }
    newBlock->data = ((char*) newBlock) + sizeof(Block);
    newBlock->size = size;
    newBlock->next = heap;
    heap = newBlock;
}

void* fetch(size_t size) {
    Block* current = heap;
    while (current != NULL && current->size < size) {
        current = current->next;
    }

    if (current == NULL) {
        return NULL;
    }

    void* data = current->data;
    void* temp = (char*) current + current->size;
    current->data = temp;
    current->size += size;
    return data;
}

int main() {
    allocate(10);
    char* message1 = (char*) fetch(50);
    strcpy(message1, "Hello, World!");

    allocate(200);
    char* message2 = (char*) fetch(100);
    strcpy(message2, "This message may overwrite memory from previous allocations.");

    printf("%s\n", message1);
    printf("%s\n", message2);

    // Dangerous operation to read memory beyond allocated blocks
    char* message3 = (char*) message1 + 60;
    printf("%c", *message3);

    return 0;
}
