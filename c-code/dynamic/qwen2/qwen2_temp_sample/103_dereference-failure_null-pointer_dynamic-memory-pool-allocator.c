#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data;
} Node;

Node *pool[POOL_SIZE];
int pool_index = 0;

void init_pool() {
    for (int i = 0; i < POOL_SIZE; i++) {
        pool[i] = malloc(sizeof(Node));
    }
}

void *allocate_node() {
    if (pool_index >= POOL_SIZE) {
        return NULL;
    }
    return pool[pool_index++];
}

void free_node(void *node) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (pool[i] == node) {
            pool[i] = NULL;
            return;
        }
    }
}

int main() {
    init_pool();

    Node *node = allocate_node();
    if (node != NULL) {
        node->data = 42;
        printf("Allocated node with data: %d\n", node->data);
    } else {
        printf("Failed to allocate node\n");
    }

    // Intentional dereference failure (null pointer)
    Node *null_node = NULL;
    printf("Data from null node: %d\n", null_node->data); // Dereference failure

    free_node(node);

    return 0;
}
