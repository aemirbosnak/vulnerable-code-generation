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

void free_nodes() {
    for (int i = 0; i < pool_index; i++) {
        free(pool[i]);
    }
    pool_index = 0;
}

int main() {
    srand(time(NULL));

    Node *nodes[10];
    for (int i = 0; i < 10; i++) {
        nodes[i] = allocate_node();
        if (!nodes[i]) {
            printf("Failed to allocate node %d\n", i);
            return 1;
        }
    }

    // Intentionally forget to free one node
    // free(nodes[5]);

    for (int i = 0; i < 10; i++) {
        if (nodes[i]) {
            printf("Node %d: Data = %d\n", i, nodes[i]->data);
        } else {
            printf("Node %d: Not allocated\n", i);
        }
    }

    free_nodes();

    return 0;
}
