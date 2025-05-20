//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMORY_SIZE 10

typedef struct memory_node {
    int value;
    struct memory_node* next;
} memory_node_t;

memory_node_t* memory[MEMORY_SIZE];
int current_position = 0;

void init_memory() {
    int i;
    for (i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = NULL;
    }
}

void add_to_memory(int value) {
    memory[current_position] = (memory_node_t*) malloc(sizeof(memory_node_t));
    memory[current_position]->value = value;
    memory[current_position]->next = NULL;
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
    init_memory();
    int i;
    for (i = 0; i < 10; i++) {
        add_to_memory(i);
    }
    int value = get_from_memory();
    while (value != -1) {
        printf("%d ", value);
        value = get_from_memory();
    }
    printf("\n");
    return 0;
}