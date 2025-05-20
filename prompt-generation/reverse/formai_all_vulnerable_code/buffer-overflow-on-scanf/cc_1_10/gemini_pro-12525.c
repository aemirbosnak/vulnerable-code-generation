//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *items;
    int top;
    int size;
} Stack;

Stack *createStack(int size) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->items = (int *) malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack *stack, int item) {
    if (stack->top == stack->size - 1) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

void moveDisks(int numDisks, Stack *source, Stack *destination, Stack *auxiliary) {
    if (numDisks == 1) {
        int disk = pop(source);
        push(destination, disk);
        printf("Move disk %d from stack %d to stack %d\n", disk, source->top + 1, destination->top + 1);
    } else {
        moveDisks(numDisks - 1, source, auxiliary, destination);
        int disk = pop(source);
        push(destination, disk);
        printf("Move disk %d from stack %d to stack %d\n", disk, source->top + 1, destination->top + 1);
        moveDisks(numDisks - 1, auxiliary, destination, source);
    }
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    Stack *source = createStack(numDisks);
    Stack *destination = createStack(numDisks);
    Stack *auxiliary = createStack(numDisks);

    for (int i = numDisks; i >= 1; i--) {
        push(source, i);
    }

    moveDisks(numDisks, source, destination, auxiliary);

    return 0;
}