//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    char name[20];
    size_t size;
} Block;

int numBlocks = 0;
Block *memory = (void*)0;

void init() {
    memory = (Block*)malloc(sizeof(Block) * MAX_SIZE);
    memset(memory, 0, sizeof(Block) * MAX_SIZE);
}

void addBlock(char *name, size_t size) {
    if (numBlocks >= MAX_SIZE) {
        printf("Error: Maximum number of blocks reached.\n");
        return;
    }

    Block *newBlock = &memory[numBlocks];
    strncpy(newBlock->name, name, 20);
    newBlock->size = size;

    numBlocks++;
}

void displayBlocks() {
    printf("Name\tSize\n");

    for (int i = 0; i < numBlocks; i++) {
        printf("%s\t%zu\n", memory[i].name, memory[i].size);
    }
}

void displayFreeBlocks() {
    printf("Free blocks:\n");

    for (int i = 0; i < numBlocks; i++) {
        if (memory[i].size == 0) {
            printf("%s\n", memory[i].name);
        }
    }
}

void displayUsedBlocks() {
    printf("Used blocks:\n");

    for (int i = 0; i < numBlocks; i++) {
        if (memory[i].size > 0) {
            printf("%s\t%zu\n", memory[i].name, memory[i].size);
        }
    }
}

int main() {
    init();

    addBlock("Stack", 1024);
    addBlock("Heap", 2048);
    addBlock("Data", 4096);

    displayBlocks();

    return 0;
}