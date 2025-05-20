#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* head = NULL;

Block* allocate(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return (Block*)((char*)new_block + sizeof(Block));
}

void deallocate(void* ptr) {
    Block* current = head;
    Block* previous = NULL;

    while (current != NULL) {
        if (current == ptr - sizeof(Block)) {
            if (previous)
                previous->next = current->next;
            else
                head = current->next;

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    fprintf(stderr, "Invalid pointer\n");
}

int main() {
    void* data1 = allocate(100);
    void* data2 = allocate(200);
    void* data3 = allocate(300);

    char* message = "This is a test message";
    strcpy((char*)data1, message);

    deallocate(data1);
    deallocate(data2); // Forgotten memory

    printf("%s\n", (char*)data3);

    return 0;
}
