//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MIN_VALUE -100000
#define MAX_VALUE 100000

typedef struct {
    int array[MAX_SIZE];
    int top;
} Stack;

void initialize_stack(Stack *stack) {
    stack->top = -1;
}

bool is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", value);
        return;
    }

    stack->array[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }

    return stack->array[stack->top--];
}

int main() {
    Stack num_stack;
    initialize_stack(&num_stack);

    int a = 5, b = 3, sum, temp;

    push(&num_stack, a);
    push(&num_stack, b);

    if (is_full(&num_stack)) {
        printf("Error: Stack overflow!\n");
        return EXIT_FAILURE;
    }

    sum = pop(&num_stack) + pop(&num_stack);
    push(&num_stack, sum);

    printf("The sum of %d and %d is %d\n", a, b, sum);

    while (!is_empty(&num_stack)) {
        temp = pop(&num_stack);
        printf("Popped value: %d\n", temp);
    }

    printf("The stack is empty.\n");

    // Power of a number using stack
    int base = 2, exponent;

    initialize_stack(&num_stack);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    for (int i = 0; i < exponent; i++) {
        push(&num_stack, base);
        base = base * 2;
    }

    int result = 1;

    while (!is_empty(&num_stack)) {
        result *= pop(&num_stack);
    }

    printf("2 raised to the power of %d is %d\n", exponent, result);

    return EXIT_SUCCESS;
}