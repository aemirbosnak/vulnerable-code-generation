//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MEMORY 1000000 // 1 MB

// Node structure for linked list
typedef struct node {
    size_t size;
    bool is_allocated;
    struct node* next;
} Node;

// Linked list for tracking memory allocation
Node* head = NULL;

// Function prototypes
void init();
void* my_malloc(size_t size);
void my_free(void* ptr);
void print_memory_usage();

int main() {
    init();

    int* a = my_malloc(10 * sizeof(int));
    int* b = my_malloc(20 * sizeof(int));
    int* c = my_malloc(30 * sizeof(int));

    printf("Allocated memory: %zu bytes\n", 10 * sizeof(int) + 20 * sizeof(int) + 30 * sizeof(int));

    my_free(a);
    my_free(b);

    printf("Free memory: %zu bytes\n", 20 * sizeof(int) + 30 * sizeof(int));

    return 0;
}

void init() {
    head = NULL;
}

void* my_malloc(size_t size) {
    Node* current = head;
    while (current!= NULL) {
        if (current->size == size &&!current->is_allocated) {
            current->is_allocated = true;
            return (void*)(++current);
        }
        current = current->next;
    }

    if (head == NULL) {
        head = malloc(sizeof(Node));
        if (head == NULL) {
            printf("Out of memory!\n");
            return NULL;
        }
        head->size = size;
        head->is_allocated = true;
        head->next = NULL;
        return (void*)(++head);
    } else {
        printf("Out of memory!\n");
        return NULL;
    }
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Node* current = head;
    while (current!= NULL && (void*)current!= ptr) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid pointer!\n");
        return;
    }

    current->is_allocated = false;
}

void print_memory_usage() {
    Node* current = head;
    size_t total_memory = 0;

    while (current!= NULL) {
        if (current->is_allocated) {
            total_memory += current->size;
        }
        current = current->next;
    }

    printf("Total memory usage: %zu bytes\n", total_memory);
}