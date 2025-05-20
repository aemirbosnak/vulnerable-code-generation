//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKS 10
#define MAX_DISKS 100

typedef struct {
    int top;
    int* stack;
} Stack;

void push(Stack* s, int value) {
    if (s->top >= MAX_DISKS) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 1;
    }

    Stack stacks[MAX_STACKS];
    for (int i = 0; i < MAX_STACKS; i++) {
        stacks[i].top = -1;
        stacks[i].stack = malloc(MAX_DISKS * sizeof(int));
    }

    int source = 0;
    int destination = MAX_STACKS - 1;
    int aux = 0;

    for (int i = n; i > 0; i--) {
        push(&stacks[source], i);
    }

    printf("Initial configuration:\n");
    for (int i = 0; i < MAX_STACKS; i++) {
        printf("Stack %d: ", i);
        for (int j = stacks[i].top; j >= 0; j--) {
            printf("%d ", pop(&stacks[i]));
        }
        printf("\n");
    }

    while (source!= destination) {
        while (source!= destination && stacks[source].top > 0) {
            push(&stacks[destination], pop(&stacks[source]));
        }
        while (source!= destination && stacks[destination].top > 0) {
            pop(&stacks[destination]);
        }
        push(&stacks[source], pop(&stacks[destination]));
        aux = destination;
        destination = source;
        source = aux;
    }

    printf("\nFinal configuration:\n");
    for (int i = 0; i < MAX_STACKS; i++) {
        printf("Stack %d: ", i);
        for (int j = stacks[i].top; j >= 0; j--) {
            printf("%d ", pop(&stacks[i]));
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_STACKS; i++) {
        free(stacks[i].stack);
    }

    return 0;
}