//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->size = MAX_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *myMalloc(size_t num) {
    Block *current = freeList;
    while (current->size < num) {
        current = current->next;
        if (current == (void*)0) {
            printf("Out of memory\n");
            exit(1);
        }
    }
    if (current->size == num) {
        current->free = 0;
        return (void*)(++current);
    } else {
        Block *newBlock = (void*)((char*)current + num + sizeof(Block));
        newBlock->size = current->size - num - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = num;
        current->free = 0;
        return (void*)(++current);
    }
}

void myFree(void* ptr) {
    if (ptr < freeList || ptr >= (void*)freeList->next) {
        printf("Invalid pointer\n");
        return;
    }
    Block* blk = (Block*)ptr;
    --blk;
    blk->free = 1;
}

int main() {
    init();
    int choice;
    while(1) {
        printf("\n1. Malloc\n2. Free\n3. Display memory status\n4. Exit");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int size;
                printf("\nEnter the size of block to allocate: ");
                scanf("%d", &size);
                void* ptr = myMalloc(size);
                printf("\nBlock of size %d allocated at %p\n", size, ptr);
                break;
            }
            case 2: {
                void* ptr;
                printf("\nEnter the pointer to free: ");
                scanf("%p", &ptr);
                myFree(ptr);
                break;
            }
            case 3: {
                Block* current = freeList->next;
                printf("\nMemory status:\n");
                while(current!= NULL) {
                    printf("\nBlock at %p of size %d is ", current, current->size);
                    if(current->free == 1)
                        printf("free\n");
                    else
                        printf("allocated\n");
                    current = current->next;
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("\nInvalid choice!");
            }
        }
    }
    return 0;
}