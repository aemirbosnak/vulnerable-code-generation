//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

void initializeStack(Stack *stack, int capacity) {
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int numDisks;

    printf("Enter number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Invalid number of disks\n");
        exit(EXIT_FAILURE);
    }

    Stack rods[3];

    for (int i = 0; i < 3; ++i) {
        initializeStack(&rods[i], numDisks);
    }

    for (int i = numDisks; i > 0; --i) {
        push(&rods[0], i);
    }

    hanoi(numDisks, 'A', 'C', 'B');

    return EXIT_SUCCESS;
}