//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
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
        printf("Error: stack is empty\n");
        exit(1);
    }

    int data = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);

    return data;
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack *a = (stack *)malloc(sizeof(stack));
    a->top = NULL;
    stack *b = (stack *)malloc(sizeof(stack));
    b->top = NULL;
    stack *c = (stack *)malloc(sizeof(stack));
    c->top = NULL;

    for (int i = n; i >= 1; i--) {
        push(a, i);
    }

    int moves = 0;
    int min_moves = (1 << n) - 1;

    while (c->top == NULL) {
        if (a->top != NULL && (b->top == NULL || a->top->data < b->top->data)) {
            push(b, pop(a));
            printf("Move disk %d from A to B\n", b->top->data);
        } else if (b->top != NULL && (c->top == NULL || b->top->data < c->top->data)) {
            push(c, pop(b));
            printf("Move disk %d from B to C\n", c->top->data);
        } else if (a->top != NULL && (c->top == NULL || a->top->data < c->top->data)) {
            push(c, pop(a));
            printf("Move disk %d from A to C\n", c->top->data);
        }

        moves++;
    }

    printf("Number of moves: %d\n", moves);
    printf("Minimum number of moves: %d\n", min_moves);

    return 0;
}