//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

void initialize(Stack *stack, int capacity) {
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (stack->top >= stack->capacity - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

void print_stack(Stack *stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    Stack rods[3];
    int disks;

    initialize(&rods[0], 3);
    initialize(&rods[1], 3);
    initialize(&rods[2], 3);

    printf("Enter number of disks: ");
    scanf("%d", &disks);

    for (int i = disks; i > 0; i--) {
        push(&rods[0], i);
    }

    hanoi(disks, 'A', 'C', 'B');

    free(rods[0].array);
    free(rods[1].array);
    free(rods[2].array);

    return 0;
}