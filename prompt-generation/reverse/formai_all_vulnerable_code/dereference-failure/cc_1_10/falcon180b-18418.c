//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void* my_malloc(size_t size);
void my_free(void* ptr);
void* my_realloc(void* ptr, size_t size);

// Global variables
size_t total_allocated = 0;
size_t max_allocated = 0;
int num_allocations = 0;
int num_frees = 0;

int main() {
    void* ptr1 = my_malloc(10);
    void* ptr2 = my_malloc(20);
    void* ptr3 = my_malloc(30);

    printf("Allocated %zu bytes\n", total_allocated);
    printf("Max allocated: %zu bytes\n", max_allocated);
    printf("Number of allocations: %d\n", num_allocations);
    printf("Number of frees: %d\n", num_frees);

    my_free(ptr1);
    my_free(ptr2);

    ptr3 = my_realloc(ptr3, 40);

    printf("Allocated %zu bytes\n", total_allocated);
    printf("Max allocated: %zu bytes\n", max_allocated);
    printf("Number of allocations: %d\n", num_allocations);
    printf("Number of frees: %d\n", num_frees);

    return 0;
}

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    total_allocated += size;
    if (total_allocated > max_allocated) {
        max_allocated = total_allocated;
    }
    num_allocations++;
    return ptr;
}

void my_free(void* ptr) {
    free(ptr);
    total_allocated -= malloc_usable_size(ptr);
}

void* my_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    total_allocated += size - malloc_usable_size(ptr);
    if (total_allocated > max_allocated) {
        max_allocated = total_allocated;
    }
    num_allocations++;
    return new_ptr;
}