//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        fprintf(stderr, "Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int factorial(int n, Stack *stack) {
    if (n > 0) {
        push(stack, n);
        return n * factorial(n - 1, stack);
    } else if (n == 0) {
        return pop(stack);
    } else {
        fprintf(stderr, "Invalid number\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Stack stack;
    int number;

    init_stack(&stack);

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0) {
        fprintf(stderr, "Invalid number\n");
        return EXIT_FAILURE;
    }

    printf("Factorial of %d = %d\n", number, factorial(number, &stack));

    return EXIT_SUCCESS;
}