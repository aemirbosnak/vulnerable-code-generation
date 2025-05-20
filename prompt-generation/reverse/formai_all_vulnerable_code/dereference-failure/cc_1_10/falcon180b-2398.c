//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a stack node
typedef struct {
    void *data; // Pointer to the data
    struct stack_node *next; // Pointer to the next node
} stack_node_t;

// Define the structure of the stack
typedef struct {
    stack_node_t *top; // Pointer to the top of the stack
} stack_t;

// Initialize an empty stack
void init_stack(stack_t *stack) {
    stack->top = NULL;
}

// Push a new node onto the stack
void push(stack_t *stack, void *data) {
    stack_node_t *node = malloc(sizeof(stack_node_t));
    if (node == NULL) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// Pop a node from the stack and return its data
void *pop(stack_t *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    stack_node_t *node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

// Print the current state of the stack
void print_stack(stack_t *stack) {
    stack_node_t *node = stack->top;
    printf("Stack:\n");
    while (node!= NULL) {
        printf("  Data: %p\n", node->data);
        node = node->next;
    }
}

// Main function to test the stack implementation
int main() {
    stack_t stack;
    init_stack(&stack);

    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        push(&stack, &i);
        print_stack(&stack);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        int *data = pop(&stack);
        printf("Popped data: %d\n", *data);
        print_stack(&stack);
    }

    return 0;
}