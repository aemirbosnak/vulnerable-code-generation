//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_BLOCKS 1000

typedef struct {
    int blockSize;
    char* blockAddress;
} MemoryBlock;

int memoryBlocksCount = 0;
MemoryBlock memoryBlocks[MAX_MEMORY_BLOCKS];

void addMemoryBlock(int blockSize, char* blockAddress) {
    if (memoryBlocksCount >= MAX_MEMORY_BLOCKS) {
        printf("Error: Maximum memory blocks reached!\n");
        return;
    }
    memoryBlocks[memoryBlocksCount].blockSize = blockSize;
    memoryBlocks[memoryBlocksCount].blockAddress = blockAddress;
    memoryBlocksCount++;
}

void removeMemoryBlock(char* blockAddress) {
    int i;
    for (i = 0; i < memoryBlocksCount; i++) {
        if (memoryBlocks[i].blockAddress == blockAddress) {
            memoryBlocks[i] = memoryBlocks[--memoryBlocksCount];
            break;
        }
    }
}

void printMemoryBlocks() {
    int i;
    for (i = 0; i < memoryBlocksCount; i++) {
        printf("Block %d: Size = %d, Address = %p\n", i+1, memoryBlocks[i].blockSize, memoryBlocks[i].blockAddress);
    }
}

int main() {
    char* blockAddress;
    int blockSize;

    while (1) {
        printf("\nEnter block size (in bytes) or 0 to exit: ");
        scanf("%d", &blockSize);
        if (blockSize == 0) {
            break;
        }
        blockAddress = (char*)malloc(blockSize);
        if (blockAddress == NULL) {
            printf("Error: Memory allocation failed!\n");
        } else {
            addMemoryBlock(blockSize, blockAddress);
        }
    }

    printf("\nMemory blocks:\n");
    printMemoryBlocks();

    while (1) {
        printf("\nEnter block address to remove or 0 to exit: ");
        scanf("%p", &blockAddress);
        if (blockAddress == NULL) {
            break;
        }
        removeMemoryBlock(blockAddress);
    }

    printf("\nFinal memory blocks:\n");
    printMemoryBlocks();

    return 0;
}