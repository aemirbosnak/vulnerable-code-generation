//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int capacity;
    int* stack;
} Stack;

void init(Stack* s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int*)malloc(capacity * sizeof(int));
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == s->capacity - 1;
}

void push(Stack* s, int value) {
    if (is_full(s)) {
        printf("The stack is full. Cannot push %d.\n", value);
        return;
    }
    s->stack[++s->top] = value;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("The stack is empty. Cannot pop.\n");
        return -1;
    }
    return s->stack[s->top--];
}

void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack is:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_disk(Stack* from, Stack* to, int n) {
    if (n == 1) {
        pop(from);
        push(to, pop(from));
    } else {
        move_disk(from, to, n - 1);
        pop(from);
        push(to, pop(from));
        move_disk(from, to, n - 1);
    }
}

int main() {
    Stack from, to, temp;
    init(&from, 5);
    init(&to, 5);
    init(&temp, 5);

    printf("Initial state:\n");
    print_stack(&from);

    int n = 4;
    printf("Moving %d disks from ", n);
    print_stack(&from);
    printf("to ");
    print_stack(&to);
    printf(":\n");

    move_disk(&from, &to, n);

    printf("Final state:\n");
    print_stack(&to);

    return 0;
}