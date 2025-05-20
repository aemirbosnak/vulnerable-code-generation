//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* data;
} Stack;

void createStack(Stack* s, int size) {
    s->size = size;
    s->data = malloc(size * sizeof(int));
}

void destroyStack(Stack* s) {
    free(s->data);
}

void push(Stack* s, int value) {
    if (s->size == 0) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    s->data[s->size - 1] = value;
}

int pop(Stack* s) {
    if (s->size == 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int value = s->data[s->size - 1];
    s->size--;
    return value;
}

void printStack(Stack* s) {
    for (int i = s->size - 1; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void hanoi(int n, Stack* source, Stack* destination, Stack* auxiliary) {
    if (n == 1) {
        push(destination, pop(source));
    } else {
        hanoi(n - 1, source, auxiliary, destination);
        push(destination, pop(source));
        hanoi(n - 1, auxiliary, destination, source);
    }
}

int main() {
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    Stack source, destination, auxiliary;
    createStack(&source, n);
    createStack(&destination, n);
    createStack(&auxiliary, n);
    for (int i = n - 1; i >= 0; i--) {
        push(&source, i + 1);
        printStack(&source);
    }
    hanoi(n, &source, &destination, &auxiliary);
    printStack(&destination);
    destroyStack(&source);
    destroyStack(&destination);
    destroyStack(&auxiliary);
    return 0;
}