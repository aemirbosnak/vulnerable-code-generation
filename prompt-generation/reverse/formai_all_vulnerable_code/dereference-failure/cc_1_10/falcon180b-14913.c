//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define STACK_SIZE 10000

typedef struct {
    int top;
    int *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->stack = (int *) malloc(STACK_SIZE * sizeof(int));
}

void push(Stack *s, int x) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = x;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void move(int n, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 1;
    }
    srand(time(NULL));
    Stack stack;
    init_stack(&stack);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}