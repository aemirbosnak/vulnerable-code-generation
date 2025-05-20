#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pool {
    char *data;
    size_t size;
    struct pool *next;
} Pool;

Pool *head = NULL;

void alloc_mem(size_t size) {
    Pool *new_pool = (Pool *)malloc(sizeof(Pool));
    new_pool->data = malloc(size);
    new_pool->size = size;
    new_pool->next = head;
    head = new_pool;
}

void free_mem(Pool *pool) {
    free(pool->data);
    free(pool);
}

void show_mem() {
    for (Pool *current = head; current != NULL; current = current->next) {
        printf("Address: %p, Size: %d, Data: ", current, current->size);
        gets(current->data);
    }
}

int main() {
    char buffer[1];
    alloc_mem(1024);
    printf("Enter input (overflowing the buffer): ");
    scanf("%s", buffer);
    show_mem();
    free_mem(head);
    return 0;
}
