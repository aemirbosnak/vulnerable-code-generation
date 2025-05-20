//Falcon-180B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024
#define MAX_BLOCKS 1000

typedef struct {
    size_t size;
    char data[MAX_BLOCK_SIZE];
} Block;

Block* free_list = (void*)0;
Block* used_list = (void*)0;

void initialize() {
    Block* block = (void*)malloc(sizeof(Block) + MAX_BLOCK_SIZE);
    if (block == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    block->size = MAX_BLOCK_SIZE;
    block->data[0] = '\0';
    free_list = block;
}

void* my_malloc(size_t size) {
    Block* current = free_list;
    while (current!= NULL && current->size < size) {
        current = current->data;
    }
    if (current == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    Block* next = (void*)((char*)current + size + sizeof(Block));
    if ((char*)next > (char*)current + MAX_BLOCK_SIZE) {
        printf("Out of memory\n");
        exit(1);
    }
    current->size = size;
    current->data[size] = '\0';
    free_list = next;
    return current->data;
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Block* block = (void*)((char*)ptr - sizeof(Block));
    block->size = 0;
    block->data[0] = '\0';
    block->data[MAX_BLOCK_SIZE - 1] = '\0';
    block = (void*)((char*)block + sizeof(Block));
    while (block < used_list && block->size == 0) {
        block = (void*)((char*)block + block->size + sizeof(Block));
    }
    if (block >= used_list) {
        used_list = block;
    }
}

int main() {
    initialize();
    char* str1 = my_malloc(10);
    strcpy(str1, "hello");
    char* str2 = my_malloc(20);
    strcpy(str2, "world");
    printf("%s %s\n", str1, str2);
    my_free(str1);
    my_free(str2);
    return 0;
}