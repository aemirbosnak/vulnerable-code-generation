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
        if (pool[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
}

Node* allocate_node() {
    if (pool_index >= POOL_SIZE) {
        fprintf(stderr, "Pool is full\n");
        return NULL;
    }
    return pool[pool_index++];
}

void free_node(Node *node) {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (pool[i] == node) {
            pool[i] = NULL;
            return;
        }
    }
    fprintf(stderr, "Node not found in pool\n");
}

int main() {
    init_pool();

    Node *node = allocate_node();
    if (node != NULL) {
        node->data = 42;
        printf("Allocated node with data: %d\n", node->data);
    }

    free_node(node);

    // Dereference failure (null pointer)
    printf("Data after freeing: %d\n", node->data); // This will cause a segmentation fault

    return 0;
}
