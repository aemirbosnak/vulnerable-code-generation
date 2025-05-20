//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

typedef struct _stack {
    node *top;
} stack;

void push(stack *s, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    int data = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peek(stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

void move_disks(int n, stack *source, stack *destination, stack *auxiliary) {
    if (n == 1) {
        int disk = pop(source);
        push(destination, disk);
        printf("Move disk %d from %s to %s\n", disk, "A", "B");
        return;
    }
    move_disks(n - 1, source, auxiliary, destination);
    int disk = pop(source);
    push(destination, disk);
    printf("Move disk %d from %s to %s\n", disk, "A", "B");
    move_disks(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack *source = (stack *)malloc(sizeof(stack));
    source->top = NULL;
    stack *destination = (stack *)malloc(sizeof(stack));
    destination->top = NULL;
    stack *auxiliary = (stack *)malloc(sizeof(stack));
    auxiliary->top = NULL;

    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    move_disks(n, source, destination, auxiliary);

    return 0;
}