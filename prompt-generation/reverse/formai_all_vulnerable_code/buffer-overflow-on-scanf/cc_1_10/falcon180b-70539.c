//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int top;
    int capacity;
} Stack;

void init_stack(Stack *s, int capacity) {
    s->stack = (int *) malloc(capacity * sizeof(int));
    if (s->stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = capacity;
}

void push(Stack *s, int x) {
    if (s->top == s->capacity - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = x;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    int x = s->stack[s->top];
    s->top--;
    return x;
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

void toh(int n, Stack *src, Stack *dest, Stack *aux) {
    if (n == 1) {
        push(dest, pop(src));
        return;
    }
    toh(n - 1, src, aux, dest);
    push(dest, pop(src));
    toh(n - 1, aux, dest, src);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    Stack src, dest, aux;
    init_stack(&src, n);
    init_stack(&dest, n);
    init_stack(&aux, n);
    for (int i = n - 1; i >= 0; i--) {
        push(&src, i);
    }
    printf("Initial configuration:\n");
    print_stack(&src);
    toh(n, &src, &dest, &aux);
    printf("Final configuration:\n");
    print_stack(&dest);
    return 0;
}