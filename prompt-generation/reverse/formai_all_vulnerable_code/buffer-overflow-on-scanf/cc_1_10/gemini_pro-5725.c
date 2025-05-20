//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->arr = (int *) malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack *stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void towerOfHanoi(int n, Stack *source, Stack *destination, Stack *auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source->top, destination->top);
        push(destination, pop(source));
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source->top, destination->top);
    push(destination, pop(source));
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack *source = createStack(n);
    Stack *destination = createStack(n);
    Stack *auxiliary = createStack(n);

    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    towerOfHanoi(n, source, destination, auxiliary);

    return 0;
}