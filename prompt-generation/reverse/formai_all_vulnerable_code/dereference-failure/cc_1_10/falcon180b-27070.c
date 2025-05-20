//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000

// Global variables
char *heap_start;
char *heap_end;
char *heap_current;

// Function prototypes
void initialize_heap();
void *my_malloc(size_t size);
void my_free(void *ptr);

int main() {
    initialize_heap();

    // Test allocations and frees
    void *ptr1 = my_malloc(10);
    void *ptr2 = my_malloc(20);
    void *ptr3 = my_malloc(30);

    printf("Allocated %d bytes at %p\n", 10, ptr1);
    printf("Allocated %d bytes at %p\n", 20, ptr2);
    printf("Allocated %d bytes at %p\n", 30, ptr3);

    my_free(ptr1);
    my_free(ptr3);

    printf("Freed %d bytes at %p\n", 10, ptr1);
    printf("Freed %d bytes at %p\n", 30, ptr3);

    return 0;
}

void initialize_heap() {
    heap_start = (char *) malloc(HEAP_SIZE);
    heap_end = heap_start + HEAP_SIZE;
    heap_current = heap_start;
}

void *my_malloc(size_t size) {
    char *result;

    if ((heap_end - heap_current) >= size) {
        result = heap_current;
        heap_current += size;
    } else {
        printf("Out of memory\n");
        exit(1);
    }

    return result;
}

void my_free(void *ptr) {
    // Do nothing for now
}