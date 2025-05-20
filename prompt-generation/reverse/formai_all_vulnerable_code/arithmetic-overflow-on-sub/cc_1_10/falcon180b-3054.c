//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100
#define STACK_SIZE 100

typedef struct {
    int size;
    int top;
    int *stack;
} Stack;

void create_stack(Stack *s, int size) {
    s->size = size;
    s->top = -1;
    s->stack = malloc(size * sizeof(int));
}

void push(Stack *s, int value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Empty stack\n");
    } else {
        printf("Stack: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->stack[i]);
        }
        printf("\n");
    }
}

void move_disk(int n, Stack *from, Stack *to, Stack *aux) {
    if (n == 1) {
        push(to, pop(from));
    } else {
        move_disk(n - 1, from, aux, to);
        push(to, pop(from));
        move_disk(n - 1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack from, to, aux;
    create_stack(&from, n);
    create_stack(&to, n);
    create_stack(&aux, n);

    for (int i = n; i >= 1; i--) {
        push(&from, i);
    }

    printf("Initial state:\n");
    print_stack(&from);

    move_disk(n, &from, &to, &aux);

    printf("Final state:\n");
    print_stack(&to);

    return 0;
}