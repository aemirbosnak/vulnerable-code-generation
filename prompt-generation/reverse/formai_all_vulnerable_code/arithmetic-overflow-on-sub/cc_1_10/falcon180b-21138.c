//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int top;
    int *stacks;
} Stack;

void create_stack(Stack *s, int size) {
    s->top = -1;
    s->stacks = (int *)malloc(size * sizeof(int));
}

void push(Stack *s, int disk) {
    if (s->top >= MAX_DISKS - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->top++;
    s->stacks[s->top] = disk;
}

int pop(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int disk = s->stacks[s->top];
    s->top--;
    return disk;
}

void move_disk(Stack *from, Stack *to, int n) {
    if (n == 1) {
        push(to, pop(from));
    } else {
        move_disk(from, to, n - 1);
        push(to, pop(from));
        move_disk(from, to, n - 1);
    }
}

void print_stack(Stack *s) {
    if (s->top < 0) {
        printf("Empty Stack\n");
    } else {
        printf("Stack: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->stacks[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack from, to, temp;
    create_stack(&from, n);
    create_stack(&to, n);
    create_stack(&temp, n);

    for (int i = n; i > 0; i--) {
        push(&from, i);
    }

    printf("Initial State:\n");
    print_stack(&from);

    move_disk(&from, &to, n);

    printf("Final State:\n");
    print_stack(&to);

    return 0;
}