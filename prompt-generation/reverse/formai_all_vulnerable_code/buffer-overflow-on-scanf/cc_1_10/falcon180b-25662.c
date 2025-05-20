//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

void push(int *stack, int *top, int value) {
    if (*top == STACK_SIZE - 1) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    (*top)++;
    stack[*top] = value;
}

int pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    return value;
}

void print_stack(int *stack, int top) {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    int stack[STACK_SIZE];
    int top = -1;

    push(stack, &top, n);

    printf("Moving %d disks from rod %d to rod %d using rod %d as auxiliary:\n", n, from_rod, to_rod, aux_rod);

    while (top!= -1) {
        int value = pop(stack, &top);
        if (value == -1) {
            continue;
        }

        if (top == 0) {
            printf("Move disk %d from rod %d to rod %d.\n", value, from_rod, to_rod);
        } else {
            push(stack, &top, value);
            printf("Move disk %d from rod %d to rod %d.\n", value, from_rod, aux_rod);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}