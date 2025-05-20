//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100000

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

Block *freeList = (void*)0;
char heap[HEAP_SIZE];

void init() {
    freeList = (Block*)heap;
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current!= freeList)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }

    return NULL;
}

void myFree(void* ptr) {
    if (ptr == NULL)
        return;

    Block* blk = (Block*)ptr;
    --blk;
    blk->free = 1;
}

int main() {
    int i, choice, size;

    init();

    do {
        printf("\n");
        printf("1. Malloc\n");
        printf("2. Free\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of the block: ");
                scanf("%d", &size);
                void* ptr = myMalloc(size);
                if(ptr!= NULL)
                    printf("Block of size %d allocated at %p\n", size, ptr);
                else
                    printf("Memory not available\n");
                break;

            case 2:
                printf("Enter the size of the block to be freed: ");
                scanf("%d", &size);
                myFree(malloc(size));
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}