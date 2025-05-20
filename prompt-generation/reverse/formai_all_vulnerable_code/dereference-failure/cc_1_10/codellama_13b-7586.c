//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: creative
/*
 * Creatively manage memory in C
 *
 * This program demonstrates how to manage memory in a creative way by
 * implementing a simple stack data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the stack data structure */
typedef struct {
    int top;
    int size;
    int *arr;
} stack_t;

/* Initialize the stack */
void stack_init(stack_t *stack, int size) {
    stack->top = -1;
    stack->size = size;
    stack->arr = malloc(sizeof(int) * size);
}

/* Push an element onto the stack */
void stack_push(stack_t *stack, int data) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

/* Pop an element from the stack */
int stack_pop(stack_t *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

/* Peek at the top element of the stack */
int stack_peek(stack_t *stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

/* Check if the stack is empty */
int stack_is_empty(stack_t *stack) {
    return stack->top == -1;
}

/* Check if the stack is full */
int stack_is_full(stack_t *stack) {
    return stack->top == stack->size - 1;
}

/* Free the memory allocated by the stack */
void stack_free(stack_t *stack) {
    free(stack->arr);
}

int main() {
    /* Create a stack with a size of 5 */
    stack_t stack;
    stack_init(&stack, 5);

    /* Push some elements onto the stack */
    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);
    stack_push(&stack, 4);
    stack_push(&stack, 5);

    /* Pop an element from the stack */
    int data = stack_pop(&stack);
    printf("Popped element: %d\n", data);

    /* Peek at the top element of the stack */
    data = stack_peek(&stack);
    printf("Top element: %d\n", data);

    /* Check if the stack is empty */
    int is_empty = stack_is_empty(&stack);
    printf("Is stack empty: %s\n", is_empty ? "true" : "false");

    /* Check if the stack is full */
    int is_full = stack_is_full(&stack);
    printf("Is stack full: %s\n", is_full ? "true" : "false");

    /* Free the memory allocated by the stack */
    stack_free(&stack);

    return 0;
}