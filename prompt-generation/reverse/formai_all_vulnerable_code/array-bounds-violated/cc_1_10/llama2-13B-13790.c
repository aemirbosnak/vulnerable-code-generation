//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MEMORY_SIZE 10
#define MEMORY_GAP 2

typedef struct memory_node {
    int value;
    struct memory_node *next;
} memory_node_t;

memory_node_t *memory[MEMORY_SIZE];
int current_position = 0;

void init_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = NULL;
    }
}

void add_to_memory(int value) {
    memory_node_t *new_node = (memory_node_t *)malloc(sizeof(memory_node_t));
    new_node->value = value;
    new_node->next = memory[current_position];
    memory[current_position] = new_node;
    current_position = (current_position + 1) % MEMORY_SIZE;
}

int get_from_memory() {
    if (current_position == -1) {
        return -1;
    }
    int value = memory[current_position]->value;
    current_position = memory[current_position]->next->next;
    return value;
}

int main() {
    srand(time(NULL));
    init_memory();

    for (int i = 0; i < 10; i++) {
        int value = rand() % 10;
        add_to_memory(value);
    }

    for (int i = 0; i < 10; i++) {
        int value = get_from_memory();
        printf("%d ", value);
    }

    return 0;
}