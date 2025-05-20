//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000

void *my_heap = NULL;

void init_heap() {
    my_heap = malloc(HEAP_SIZE);
    if (my_heap == NULL) {
        printf("Failed to initialize heap\n");
        exit(1);
    }
    printf("Heap initialized successfully\n");
}

void *my_malloc(int size) {
    void *ptr = my_heap;
    my_heap += size;
    if (my_heap - ptr > HEAP_SIZE) {
        printf("Heap overflow\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr < my_heap || ptr >= my_heap + HEAP_SIZE) {
        printf("Invalid pointer\n");
        exit(1);
    }
    my_heap = ptr;
}

int main() {
    init_heap();

    void *ptr1 = my_malloc(10);
    void *ptr2 = my_malloc(20);
    void *ptr3 = my_malloc(30);

    printf("Allocated %d bytes at %p\n", 10, ptr1);
    printf("Allocated %d bytes at %p\n", 20, ptr2);
    printf("Allocated %d bytes at %p\n", 30, ptr3);

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    return 0;
}