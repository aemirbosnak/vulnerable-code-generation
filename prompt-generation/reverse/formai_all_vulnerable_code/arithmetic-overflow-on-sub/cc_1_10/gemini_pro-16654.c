//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct stack {
    int data[STACK_SIZE];
    int top;
} stack;

void push(stack *s, int data) {
    if (s->top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = data;
}

int pop(stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

bool is_empty(stack *s) {
    return s->top == -1;
}

void tower_of_hanoi(int n, stack *from, stack *to, stack *aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    push(to, pop(from));
    tower_of_hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    stack from, to, aux;
    from.top = -1;
    to.top = -1;
    aux.top = -1;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        push(&from, i);
    }
    tower_of_hanoi(n, &from, &to, &aux);
    printf("The disks have been moved from the 'from' stack to the 'to' stack using the 'aux' stack.\n");
    return 0;
}