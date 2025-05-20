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

Node* allocate_node() {
    if (pool_index >= POOL_SIZE) {
        return NULL; // Pool is full
    }
    Node *node = malloc(sizeof(Node));
    if (!node) {
        return NULL; // Memory allocation failed
    }
    node->data = rand();
    pool[pool_index++] = node;
    return node;
}

void free_node(Node *node) {
    for (int i = 0; i < pool_index; i++) {
        if (pool[i] == node) {
            pool[i] = NULL;
            free(node);
            return;
        }
    }
    printf("Error: Attempt to free unallocated node\n");
}

int main() {
    srand(time(NULL));

    Node *nodes[10];
    for (int i = 0; i < 10; i++) {
        nodes[i] = allocate_node();
        if (!nodes[i]) {
            printf("Failed to allocate node %d\n", i);
            exit(1);
        }
    }

    // Intentionally dereference an invalid pointer
    Node *invalid_node = (Node *)0xdeadbeef;
    printf("Invalid node data: %d\n", invalid_node->data); // Dereference failure

    for (int i = 0; i < 10; i++) {
        free_node(nodes[i]);
    }

    return 0;
}
