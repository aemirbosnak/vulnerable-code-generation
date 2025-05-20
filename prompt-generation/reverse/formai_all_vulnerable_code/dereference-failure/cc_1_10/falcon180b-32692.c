//Falcon-180B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALLOCATIONS 1000000
#define MAX_ALLOCATION_SIZE 1000000

typedef struct {
    size_t size;
    char *ptr;
} Allocation;

Allocation *allocations = NULL;
size_t num_allocations = 0;

void init() {
    srand(time(NULL));
    allocations = calloc(NUM_ALLOCATIONS, sizeof(Allocation));
}

void *my_malloc(size_t size) {
    Allocation *alloc = calloc(1, sizeof(Allocation));
    if (alloc == NULL) {
        return NULL;
    }
    alloc->size = size;
    alloc->ptr = malloc(size);
    if (alloc->ptr == NULL) {
        free(alloc);
        return NULL;
    }
    num_allocations++;
    return alloc->ptr;
}

void my_free(void *ptr) {
    Allocation *alloc = NULL;
    for (int i = 0; i < num_allocations; i++) {
        if (allocations[i].ptr == ptr) {
            alloc = &allocations[i];
            break;
        }
    }
    if (alloc == NULL) {
        return;
    }
    free(alloc->ptr);
    num_allocations--;
    free(alloc);
}

void print_allocations() {
    for (int i = 0; i < num_allocations; i++) {
        printf("Allocation %d: Size %zu, Pointer %p\n", i, allocations[i].size, allocations[i].ptr);
    }
}

int main() {
    init();
    int *array = my_malloc(MAX_ALLOCATION_SIZE);
    if (array == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }
    for (int i = 0; i < MAX_ALLOCATION_SIZE; i++) {
        array[i] = rand() % 100;
    }
    printf("Array filled with random numbers.\n");
    my_free(array);
    print_allocations();
    return 0;
}