//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define STACK_SIZE 100

typedef struct {
    int top;
    int *stack;
} Stack;

void push(Stack *s, int x) {
    if (s->top >= STACK_SIZE) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = x;
}

int pop(Stack *s) {
    if (s->top <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void print_stack(Stack s) {
    printf("Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.stack[i]);
    }
    printf("\n");
}

void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        move_disk(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        move_disk(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        exit(1);
    }

    Stack stack1, stack2, stack3;
    stack1.top = -1;
    stack2.top = -1;
    stack3.top = -1;

    srand(time(NULL));
    int from_rod, to_rod, aux_rod;
    from_rod = rand() % 3;
    to_rod = rand() % 3;
    while (from_rod == to_rod) {
        to_rod = rand() % 3;
    }
    aux_rod = (from_rod + to_rod) % 3;

    move_disk(n, from_rod + 'A', to_rod + 'A', aux_rod + 'A');

    return 0;
}