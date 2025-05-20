//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

block_t *free_list = (void*)0;
char heap[HEAP_SIZE];

void init() {
    free_list = (block_t*)heap;
    free_list->size = HEAP_SIZE - sizeof(block_t);
    free_list->free = 1;
    free_list->next = (void*)0;
}

void *malloc(size_t num) {
    block_t *current = free_list;
    while (current->size < num) {
        current = current->next;
        if (current == (void*)0) {
            printf("Out of memory!\n");
            exit(1);
        }
    }
    if (current->size == num) {
        current->free = 0;
        return (void*)(++current);
    } else {
        block_t *new_block = (void*)((int)current + num + sizeof(block_t));
        new_block->size = current->size - num - sizeof(block_t);
        new_block->free = 1;
        new_block->next = current->next;
        current->size = num;
        current->free = 0;
        current->next = new_block;
        return (void*)(++current);
    }
}

void free(void* ptr) {
    if (ptr < heap || ptr >= heap + HEAP_SIZE) {
        printf("Invalid pointer!\n");
        exit(1);
    }
    block_t* blk = (block_t*)ptr;
    --blk;
    blk->free = 1;
}

int main() {
    init();
    char* str1 = (char*)malloc(10);
    char* str2 = (char*)malloc(20);
    char* str3 = (char*)malloc(30);
    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "This is a test");
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    free(str1);
    free(str2);
    free(str3);
    return 0;
}