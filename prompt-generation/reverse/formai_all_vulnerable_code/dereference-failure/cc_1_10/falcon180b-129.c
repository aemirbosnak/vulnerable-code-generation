//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int top;
    int *stack;
} Stack;

void init_stack(Stack *s, int size) {
    s->top = -1;
    s->stack = (int *) malloc(size * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->top >= MAX_DISKS - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

void print_stack(Stack *s) {
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_disk(Stack *from, Stack *to, int n) {
    if (n == 1) {
        int value = pop(from);
        push(to, value);
        printf("Move disk %d from %s to %s\n", value, "A", "C");
    } else {
        move_disk(from, to, n - 1);
        int value = pop(from);
        push(to, value);
        printf("Move disk %d from %s to %s\n", value, "A", "C");
        move_disk(to, from, n - 1);
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % (MAX_DISKS - 1) + 1;
    printf("Solving Tower of Hanoi problem with %d disks...\n", n);

    Stack from, to, temp;
    init_stack(&from, MAX_DISKS);
    init_stack(&to, MAX_DISKS);
    init_stack(&temp, MAX_DISKS);

    for (int i = n; i >= 1; i--) {
        push(&from, i);
    }

    print_stack(&from);

    move_disk(&from, &to, n);

    print_stack(&to);

    return 0;
}