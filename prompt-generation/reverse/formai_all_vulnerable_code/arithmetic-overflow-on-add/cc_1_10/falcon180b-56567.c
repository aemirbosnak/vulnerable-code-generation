//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Stack;

void init(Stack *stack, int size) {
    stack->data = (int *)malloc(size * sizeof(int));
    stack->size = size;
}

void push(Stack *stack, int value) {
    if (stack->size == stack->data[0]) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->data[0]] = value;
}

int pop(Stack *stack) {
    if (stack->data[0] == 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[--stack->data[0]];
}

void print_stack(Stack *stack) {
    for (int i = stack->data[0]; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    int n = 4;
    Stack tower;
    init(&tower, n);
    printf("Initial tower:\n");
    print_stack(&tower);

    int temp;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            push(&tower, pop(&tower));
        }
        push(&tower, pop(&tower));
    }

    printf("Tower after move:\n");
    print_stack(&tower);

    return 0;
}