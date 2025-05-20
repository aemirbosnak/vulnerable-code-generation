//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define STACK_SIZE 100

typedef struct {
    int top;
    int *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->stack = (int *) malloc(STACK_SIZE * sizeof(int));
}

void push(Stack *s, int n) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = n;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void move_disk(int n, char from, char to) {
    printf("Move disk %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(1, from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to);
    hanoi(n - 1, aux, to, from);
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
    srand(time(NULL));
    char from = 'A' + rand() % 3;
    char to = 'C' - (from - 'A') + rand() % 2;
    char aux = 'B' + (from == 'A'? 1 : -1);
    hanoi(n, from, to, aux);
    return 0;
}