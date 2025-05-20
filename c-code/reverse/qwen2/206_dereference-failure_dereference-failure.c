#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

typedef struct {
    int data[MAX_DISKS];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_DISKS - 1;
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

void towerOfHanoi(int n, Stack *source, Stack *auxiliary, Stack *destination) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    push(destination, pop(source));
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    Stack source, auxiliary, destination;
    initStack(&source);
    initStack(&auxiliary);
    initStack(&destination);

    for (int i = MAX_DISKS; i > 0; i--) {
        push(&source, i);
    }

    towerOfHanoi(MAX_DISKS, &source, &auxiliary, &destination);

    return 0;
}
