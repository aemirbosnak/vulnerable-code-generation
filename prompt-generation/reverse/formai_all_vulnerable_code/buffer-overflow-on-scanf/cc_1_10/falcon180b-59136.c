//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10
#define STACK_SIZE 1000

typedef struct {
    int top;
    int *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->stack = malloc(STACK_SIZE * sizeof(int));
}

void push(Stack *s, int data) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = data;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int data = s->stack[s->top];
    s->top--;
    return data;
}

void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Empty stack\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod, Stack *stack) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        push(stack, from_rod);
        printf("Move disk 1 from rod %c to rod %c\n", aux_rod, to_rod);
        pop(stack);
    } else {
        move_disk(n - 1, from_rod, aux_rod, to_rod, stack);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        push(stack, n);
        move_disk(n - 1, aux_rod, to_rod, from_rod, stack);
        pop(stack);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    Stack stack;
    init_stack(&stack);
    move_disk(n, 'A', 'C', 'B', &stack);
    print_stack(&stack);
    return 0;
}