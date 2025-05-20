//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DISKS 100

typedef struct {
    int top;
    int* stack;
    int capacity;
} Stack;

void init_stack(Stack* s, int capacity) {
    s->top = -1;
    s->stack = (int*)malloc(capacity * sizeof(int));
    s->capacity = capacity;
}

void push(Stack* s, int value) {
    if (s->top >= s->capacity - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = value;
}

int pop(Stack* s) {
    if (s->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    int value = s->stack[s->top];
    s->top--;
    return value;
}

void print_stack(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void move_disk(Stack* from, Stack* to, Stack* temp, int n) {
    if (n == 1) {
        push(to, pop(from));
    } else {
        move_disk(from, temp, to, n - 1);
        push(to, pop(from));
        while (n > 1) {
            push(to, pop(temp));
            n--;
        }
    }
}

int main() {
    srand(time(0));
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    Stack from, to, temp;
    init_stack(&from, n);
    init_stack(&to, n);
    init_stack(&temp, n);
    for (int i = n; i >= 1; i--) {
        push(&from, i);
    }
    printf("Initial state:\n");
    print_stack(&from);
    move_disk(&from, &to, &temp, n);
    printf("Final state:\n");
    print_stack(&to);
    return 0;
}