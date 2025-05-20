//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>

#define STACK_SIZE 100

typedef struct {
    int *stack;
    int top;
} Stack;

void init_stack(Stack *s) {
    s->stack = (int*) malloc(STACK_SIZE * sizeof(int));
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack *s) {
    if (is_empty(s)) {
        printf("Empty stack\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_tower(int n, Stack *src, Stack *dest, Stack *aux) {
    if (n == 1) {
        push(dest, pop(src));
        return;
    }
    move_tower(n - 1, src, aux, dest);
    push(dest, pop(src));
    move_tower(n - 1, aux, dest, src);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    Stack src, dest, aux;
    init_stack(&src);
    init_stack(&dest);
    init_stack(&aux);
    for (int i = n; i >= 1; i--) {
        push(&src, i);
        print_stack(&src);
        printf("Moving tower of %d disks from %s to %s:\n", i, "src", "dest");
        move_tower(i, &src, &dest, &aux);
        print_stack(&src);
        print_stack(&dest);
    }
    return 0;
}