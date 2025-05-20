#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pool {
    char* data;
    size_t size;
    struct pool* next;
} Pool;

Pool* head = NULL;

void add_to_pool(char* data, size_t size) {
    Pool* new_pool = (Pool*) malloc(sizeof(Pool));
    new_pool->data = data;
    new_pool->size = size;
    new_pool->next = head;
    head = new_pool;
}

char* get_from_pool(size_t size) {
    Pool* current = head;
    while (current->next != NULL && current->size < size) {
        current = current->next;
    }
    if (current->size >= size) {
        Pool* temp = current->next;
        current->next = current->next->next;
        return current->data;
    }
    return calloc(size, 1);
}

int main() {
    char input[10];
    printf("Enter input: ");
    gets(input);

    add_to_pool(input, 10);

    char* buf = get_from_pool(1000);
    printf("Buffer: %s\n", buf);

    strcpy(buf, "A" // Add more 'A' until the buffer overflows.
    );

    return 0;
}
