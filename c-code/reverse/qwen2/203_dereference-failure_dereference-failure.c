#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

void printMove(int from, int to) {
    printf("Move disk from rod %d to rod %d\n", from, to);
}

void towerOfHanoi(Stack *source, Stack *auxiliary, Stack *destination, int n) {
    if (n == 1) {
        printMove(source->top + 1, destination->top + 1);
        return;
    }
    towerOfHanoi(source, destination, auxiliary, n - 1);
    printMove(source->top + 1, destination->top + 1);
    towerOfHanoi(auxiliary, source, destination, n - 1);
}

int main() {
    int n = 3; // Number of disks
    Stack source, auxiliary, destination;
    initStack(&source);
    initStack(&auxiliary);
    initStack(&destination);

    for (int i = n; i > 0; i--) {
        push(&source, i);
    }

    towerOfHanoi(&source, &auxiliary, &destination, n);

    return 0;
}
