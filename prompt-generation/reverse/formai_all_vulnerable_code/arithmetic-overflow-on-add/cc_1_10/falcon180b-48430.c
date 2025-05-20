//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 1000000 // 1 MB

// Node structure definition
typedef struct Node {
    size_t size;
    int id;
    struct Node* next;
} node_t;

node_t* freelist = (void*)0; // Initialize freelist to NULL

void init() {
    freelist = (node_t*)malloc(sizeof(node_t)); // Allocate memory for the first node in the freelist
    freelist->size = HEAP_SIZE - sizeof(node_t);
    freelist->id = 0;
    freelist->next = (void*)0;
}

void* my_malloc(size_t num_bytes) {
    node_t* current = freelist;
    while (current!= NULL && current->size < num_bytes) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Out of memory\n");
        exit(1);
    }

    void* result = (void*)(++current);
    current->size -= num_bytes;
    current->id++;

    return result;
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    node_t* current = (node_t*)ptr;
    current--;

    if (current->next!= NULL) {
        current->next->id = current->id;
    }

    freelist = current;
}

int main() {
    init();

    int* a = my_malloc(10 * sizeof(int));
    int* b = my_malloc(20 * sizeof(int));
    int* c = my_malloc(30 * sizeof(int));

    printf("Allocated a: %p\n", a);
    printf("Allocated b: %p\n", b);
    printf("Allocated c: %p\n", c);

    my_free(a);
    my_free(b);
    my_free(c);

    return 0;
}