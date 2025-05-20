//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void push(int *stack, int *top, int value) {
    if (*top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    (*top)++;
    *(stack + *top) = value;
}

int pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = *(stack + *top);
    (*top)--;
    return value;
}

void print_stack(int *stack, int top) {
    for (int i = top; i >= 0; i--) {
        printf("%d ", *(stack + i));
    }
    printf("\n");
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    int stack[STACK_SIZE];
    int top = -1;
    push(stack, &top, n);

    while (top!= -1) {
        int value = pop(stack, &top);
        printf("%c -> %c\n", from_rod, to_rod);
        if (value > 1) {
            push(stack, &top, value - 1);
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