//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

void init_stack(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (int *)malloc(capacity * sizeof(int));
}

void push(Stack *s, int disk) {
    if (s->top >= s->capacity - 1) {
        printf("Error: Stack is full.\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = disk;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    int disk = s->stack[s->top];
    s->top--;
    return disk;
}

void print_stack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.stack[i]);
    }
    printf("\n");
}

void hanoi(int n, Stack *src, Stack *dst, Stack *aux) {
    if (n == 1) {
        push(dst, pop(src));
    } else {
        hanoi(n - 1, src, aux, dst);
        push(dst, pop(src));
        hanoi(n - 1, aux, dst, src);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Error: Invalid number of disks.\n");
        exit(1);
    }
    Stack src, dst, aux;
    init_stack(&src, n);
    init_stack(&dst, n);
    init_stack(&aux, n);
    for (int i = n - 1; i >= 0; i--) {
        push(&src, i + 1);
    }
    printf("Initial configuration:\n");
    print_stack(src);
    hanoi(n, &src, &dst, &aux);
    printf("Final configuration:\n");
    print_stack(dst);
    return 0;
}