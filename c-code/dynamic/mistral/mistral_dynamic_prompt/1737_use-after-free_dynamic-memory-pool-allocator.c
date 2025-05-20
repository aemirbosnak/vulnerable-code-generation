#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    void* data;
    size_t size;
    struct Pool* next;
} Pool;

Pool* head = NULL;

void alloc(size_t size) {
    Pool* new_pool = (Pool*) malloc(sizeof(Pool));
    new_pool->data = malloc(size);
    new_pool->size = size;
    new_pool->next = head;
    head = new_pool;
}

void free_pool(void* ptr) {
    Pool* current = head;
    Pool* previous = NULL;

    while (current != NULL) {
        if (current->data == ptr) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->data);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void* get_ptr(size_t index) {
    Pool* current = head;
    for (size_t i = 0; i < index && current != NULL; ++i) {
        current = current->next;
    }

    return current->data;
}

int main() {
    alloc(10);
    int* arr1 = (int*) get_ptr(0);
    arr1[0] = 42;
    alloc(20);
    int* arr2 = (int*) get_ptr(1);
    free_pool(arr1);
    arr2[0] = 1337;

    return 0;
}
