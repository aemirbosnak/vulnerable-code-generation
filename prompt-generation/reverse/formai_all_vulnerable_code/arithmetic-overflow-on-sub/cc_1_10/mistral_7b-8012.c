//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int top;
} Stack;

void push(Stack *stack, int data) {
    stack->data[stack->top++] = data;
}

int pop(Stack *stack) {
    if (stack->top <= 0) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[--stack->top];
}

void display(Stack stack) {
    printf("Stack contents: ");
    for (int i = stack.top - 1; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

int main() {
    Stack bitwise_operations;
    int a = 0x0F, b = 0x3F, c, d, e;

    push(&bitwise_operations, a);
    printf("Pushed %#x onto the stack.\n", a);

    c = a & b;
    push(&bitwise_operations, c);
    printf("Performed bitwise AND (%#x & %#x) = %#x and pushed the result onto the stack.\n", a, b, c);

    d = a | b;
    push(&bitwise_operations, d);
    printf("Performed bitwise OR (%#x | %#x) = %#x and pushed the result onto the stack.\n", a, b, d);

    e = a ^ b;
    push(&bitwise_operations, e);
    printf("Performed bitwise XOR (%#x ^ %#x) = %#x and pushed the result onto the stack.\n", a, b, e);

    display(bitwise_operations);
    printf("Stack contents after bitwise operations: ");
    while (bitwise_operations.top > 0) {
        printf("%#x ", pop(&bitwise_operations));
    }
    printf("\n");

    return EXIT_SUCCESS;
}