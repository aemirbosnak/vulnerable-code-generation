//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    void *data;
    size_t size;
} block_t;

block_t *free_list = (void*)0;

void init() {
    free_list = (block_t*)malloc(sizeof(block_t));
    free_list->data = (void*)0;
    free_list->size = 0;
}

void *my_malloc(size_t size) {
    block_t *current = free_list;
    while (current->size < size) {
        current = current->data;
    }
    if (current->size == size) {
        void *result = current->data;
        current->data = (void*)0;
        return result;
    } else {
        void *result = (void*)malloc(size);
        memcpy(result, current->data, current->size);
        free(current->data);
        current->data = result;
        current->size = size;
        return result;
    }
}

void my_free(void *ptr) {
    block_t *current = free_list;
    while (current->data!= ptr) {
        current = current->data;
    }
    current->size = 0;
    current->data = (void*)0;
}

int main() {
    init();
    void *p1 = my_malloc(10);
    void *p2 = my_malloc(20);
    void *p3 = my_malloc(30);
    printf("Allocated %d bytes\n", 10 + 20 + 30);
    my_free(p1);
    my_free(p2);
    my_free(p3);
    printf("Freed %d bytes\n", 10 + 20 + 30);
    return 0;
}