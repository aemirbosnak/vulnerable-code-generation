#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    void *mem_block;
    int size;
    struct Pool *next;
} Pool;

Pool *head = NULL;

void allocate(int size) {
    Pool *new_block = (Pool*)malloc(sizeof(Pool));
    if (!new_block) {
        printf("Out of memory\n");
        return;
    }

    new_block->mem_block = malloc(size);
    if (!new_block->mem_block) {
        printf("Out of memory\n");
        free(new_block);
        return;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* get_memory(int size) {
    Pool *temp = head;
    while (temp != NULL) {
        if (temp->size >= size) {
            void *mem = temp->mem_block;
            if (temp->size == size) {
                head = temp->next;
                temp->mem_block = NULL;
            } else {
                temp->size -= size;
                mem += size;
            }
            return mem;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    allocate(5);
    allocate(10);

    char *str1 = (char*)get_memory(11);
    strcpy(str1, "This is a test string");
    printf("%s\n", str1); // Null pointer dereference vulnerability

    allocate(20);
    char *str2 = (char*)get_memory(31);
    strcpy(str2, "This is another test string");
    printf("%s\n", str2);

    return 0;
}
