//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *data;
} Stack;

void push(Stack *s, int x) {
    if (s->size >= 0) {
        s->size++;
        s->data = realloc(s->data, s->size * sizeof(int));
        s->data[s->size - 1] = x;
    }
}

int pop(Stack *s) {
    if (s->size >= 0) {
        int x = s->data[s->size - 1];
        s->size--;
        s->data = realloc(s->data, s->size * sizeof(int));
        return x;
    } else {
        return -1;
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack A, B, C;
    A.size = -1;
    B.size = -1;
    C.size = -1;

    for (int i = n; i >= 1; i--) {
        push(&A, i);
    }

    int steps = 0;
    while (A.size > 0) {
        steps++;
        if (A.size == 1) {
            push(&B, pop(&A));
            push(&C, pop(&A));
        } else if (A.size == 2) {
            push(&B, pop(&A));
            push(&C, pop(&A));
            push(&B, pop(&C));
        } else {
            push(&C, pop(&A));
            push(&B, pop(&A));
            push(&A, pop(&C));
        }
    }

    printf("Minimum number of moves: %d\n", steps);

    return 0;
}