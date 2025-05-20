#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    char *data;
    struct Pool *next;
} Pool;

Pool *head = NULL;
const int BUFFER_SIZE = 1024;

void init() {
    head = malloc(sizeof(Pool));
    head->data = malloc(BUFFER_SIZE);
    head->next = NULL;
}

Pool* alloc(int size) {
    Pool *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(Pool));
    current = current->next;
    current->data = malloc(size);
    current->next = NULL;
    return current;
}

void free_pool(Pool *pool) {
    free(pool->data);
    Pool *temp = head;
    while (temp->next != pool) {
        temp = temp->next;
    }
    temp->next = pool->next;
    free(pool);
}

int main() {
    init();
    Pool *mem = alloc(256);
    printf("Allocation successful. Buffer address: %p\n", mem->data);

    gets(mem->data); // Buffer overflow vulnerability

    free_pool(mem);
    return 0;
}
