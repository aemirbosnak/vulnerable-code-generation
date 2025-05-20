#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t cap;
    struct Node *next;
} Node;

Node *pool = NULL;
size_t current_index = 0;

Node *create_node(size_t size) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = malloc(size);
    new_node->size = size;
    new_node->cap = size;
    new_node->next = NULL;

    if (!pool) {
        pool = new_node;
    } else {
        Node *last = pool;
        while (last->next) {
            last = last->next;
        }
        last->next = new_node;
    }

    current_index++;

    return new_node;
}

void free_node(Node *node) {
    if (node) {
        free(node->data);
        free(node);
    }
}

void free_all() {
    Node *temp;
    for (Node *curr = pool; curr; curr = temp) {
        temp = curr->next;
        free_node(curr);
    }
    pool = NULL;
    current_index = 0;
}

void usage() {
    printf("Usage: allocator [size] [input]\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usage();
        return 1;
    }

    size_t size = atoi(argv[1]);
    if (size <= 0) {
        printf("Error: Invalid size.\n");
        usage();
        return 1;
    }

    Node *node = create_node(size);
    gets(node->data);

    free_all();
    return 0;
}
