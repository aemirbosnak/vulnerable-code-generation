//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000000 // 1 MB heap

// Our heap structure
typedef struct {
    char *base;
    char *end;
    char *ptr;
} Heap;

// Initialize our heap
void init_heap(Heap *heap) {
    heap->base = malloc(HEAP_SIZE);
    heap->end = heap->base + HEAP_SIZE;
    heap->ptr = heap->base;
}

// Allocate memory from our heap
void *my_malloc(Heap *heap, size_t size) {
    void *ptr = heap->ptr;
    if (heap->ptr + size > heap->end) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    heap->ptr += size;
    return ptr;
}

// Free memory back to our heap
void my_free(Heap *heap, void *ptr) {
    if (ptr < heap->base || ptr >= heap->end) {
        fprintf(stderr, "Invalid pointer\n");
        exit(1);
    }
    heap->ptr = ptr;
}

// Our main function
int main() {
    Heap heap;
    init_heap(&heap);

    char *str1 = my_malloc(&heap, 10);
    char *str2 = my_malloc(&heap, 20);
    char *str3 = my_malloc(&heap, 30);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "How are you?");

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    my_free(&heap, str1);
    my_free(&heap, str2);
    my_free(&heap, str3);

    return 0;
}