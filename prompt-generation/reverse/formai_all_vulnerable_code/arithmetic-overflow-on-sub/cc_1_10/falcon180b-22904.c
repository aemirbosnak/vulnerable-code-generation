//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int size;
    int *arr;
} Stack;

void init(Stack *st, int size) {
    st->size = size;
    st->arr = (int *)malloc(sizeof(int) * size);
}

void push(Stack *st, int value) {
    if (st->size == 0) {
        printf("Stack Overflow\n");
    } else {
        st->arr[st->size - 1] = value;
    }
}

int pop(Stack *st) {
    if (st->size == 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = st->arr[st->size - 1];
        st->size--;
        return value;
    }
}

void moveDisk(Stack *src, Stack *dest, Stack *aux, int n) {
    if (n == 1) {
        push(dest, pop(src));
    } else {
        moveDisk(src, aux, dest, n - 1);
        push(dest, pop(src));
        moveDisk(aux, dest, src, n - 1);
    }
}

void main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack source, destination, auxiliary;
    init(&source, n);
    init(&destination, n);
    init(&auxiliary, n);

    printf("Initial state:\n");
    for (int i = n - 1; i >= 0; i--) {
        push(&source, i + 1);
    }

    printf("Move %d disks from ", n);
    moveDisk(&source, &destination, &auxiliary, n);
    printf(" to %s:\n", "destination");

    for (int i = 0; i < n; i++) {
        printf("%d ", pop(&destination));
    }
}